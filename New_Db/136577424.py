import sys
readline=sys.stdin.readline

class Graph:
    def __init__(self,V,edges=False,graph=False,directed=False,weighted=False,inf=float("inf")):
        self.V=V
        self.directed=directed
        self.weighted=weighted
        self.inf=inf
        if not graph:
            self.edges=edges
            self.graph=[[] for i in range(self.V)]
            if weighted:
                for i,j,d in self.edges:
                    self.graph[i].append((j,d))
                    if not self.directed:
                        self.graph[j].append((i,d))
            else:
                for i,j in self.edges:
                    self.graph[i].append(j)
                    if not self.directed:
                        self.graph[j].append(i)
        else:
            self.graph=graph
            self.edges=[]
            for i in range(self.V):
                if self.weighted:
                    for j,d in self.graph[i]:
                        if self.directed or not self.directed and i<=j:
                            self.edges.append((i,j,d))
                else:
                    for j in self.graph[i]:
                        if self.directed or not self.directed and i<=j:
                            self.edges.append((i,j))

    def SIV_BFS(self,s,bfs_tour=False,bipartite_graph=False,linked_components=False,parents=False,unweighted_dist=False,weighted_dist=False):
        seen=[False]*self.V
        seen[s]=True
        if bfs_tour:
            bt=[s]
        if linked_components:
            lc=[s]
        if parents:
            ps=[None]*self.V
        if unweighted_dist or bipartite_graph:
            uwd=[self.inf]*self.V
            uwd[s]=0
        if weighted_dist:
            wd=[self.inf]*self.V
            wd[s]=0
        queue=deque([s])
        while queue:
            x=queue.popleft()
            for y in self.graph[x]:
                if self.weighted:
                    y,d=y
                if not seen[y]:
                    seen[y]=True
                    queue.append(y)
                    if bfs_tour:
                        bt.append(y)
                    if linked_components:
                        lc.append(y)
                    if parents:
                        ps[y]=x
                    if unweighted_dist or bipartite_graph:
                        uwd[y]=uwd[x]+1
                    if weighted_dist:
                        wd[y]=wd[x]+d
        if bipartite_graph:
            bg=[[],[]]
            for tpl in self.edges:
                i,j=tpl[:2] if self.weighted else tpl
                if uwd[i]==self.inf or uwd[j]==self.inf:
                    continue
                if not uwd[i]%2^uwd[j]%2:
                    bg=False
                    break
            else:
                for x in range(self.V):
                    if uwd[x]==self.inf:
                        continue
                    bg[uwd[x]%2].append(x)
        retu=()
        if bfs_tour:
            retu+=(bt,)
        if bipartite_graph:
            retu+=(bg,)
        if linked_components:
            retu+=(lc,)
        if parents:
            retu+=(ps,)
        if unweighted_dist:
            retu+=(uwd,)
        if weighted_dist:
            retu+=(wd,)
        if len(retu)==1:
            retu=retu[0]
        return retu

    def MIV_BFS(self,initial_vertices=False,bipartite_graph=False,linked_components=False,parents=False):
        if not initial_vertices:
            initial_vertices=[i for i in range(self.V)]
        seen=[False]*self.V
        if bipartite_graph:
            bg=[None]*self.V
            cnt=-1
        if linked_components:
            lc=[]
        if parents:
            ps=[None]*self.V
        for s in initial_vertices:
            if seen[s]:
                continue
            seen[s]=True
            if bipartite_graph:
                cnt+=1
                bg[s]=(cnt,0)
            if linked_components:
                lc.append([s])
            queue=deque([s])
            while queue:
                x=queue.popleft()
                for y in self.graph[x]:
                    if self.weighted:
                        y,d=y
                    if not seen[y]:
                        seen[y]=True
                        queue.append(y)
                        if bipartite_graph:
                            bg[y]=(cnt,bg[x][1]^1)
                        if linked_components:
                            lc[-1].append(y)
                        if parents:
                            ps[y]=x
        if bipartite_graph:
            bg_=bg
            bg=[[[],[]] for i in range(cnt+1)]
            for tpl in self.edges:
                i,j=tpl[:2] if self.weighted else tpl
                if not bg_[i][1]^bg_[j][1]:
                    bg[bg_[i][0]]=False
            for x in range(self.V):
                if bg[bg_[x][0]]:
                    bg[bg_[x][0]][bg_[x][1]].append(x)
        retu=()
        if bipartite_graph:
            retu+=(bg,)
        if linked_components:
            retu+=(lc,)
        if parents:
            retu=(ps,)
        if len(retu)==1:
            retu=retu[0]
        return retu

    def SIV_DFS(self,s,bipartite_graph=False,cycle_detection=False,directed_acyclic=False,euler_tour=False,linked_components=False,parents=False,postorder=False,preorder=False,subtree_size=False,topological_sort=False,unweighted_dist=False,weighted_dist=False):
        seen=[False]*self.V
        finished=[False]*self.V
        if directed_acyclic or cycle_detection or topological_sort:
            dag=True
        if euler_tour:
            et=[]
        if linked_components:
            lc=[]
        if parents or cycle_detection or subtree_size:
            ps=[None]*self.V
        if postorder or topological_sort:
            post=[]
        if preorder:
            pre=[]
        if subtree_size:
            ss=[1]*self.V
        if unweighted_dist or bipartite_graph:
            uwd=[self.inf]*self.V
            uwd[s]=0
        if weighted_dist:
            wd=[self.inf]*self.V
            wd[s]=0
        stack=[(s,0)] if self.weighted else [s]
        while stack:
            if self.weighted:
                x,d=stack.pop()
            else:
                x=stack.pop()
            if not seen[x]:
                seen[x]=True
                stack.append((x,d) if self.weighted else x)
                if euler_tour:
                    et.append(x)
                if linked_components:
                    lc.append(x)
                if preorder:
                    pre.append(x)
                for y in self.graph[x]:
                    if self.weighted:
                        y,d=y
                    if not seen[y]:
                        stack.append((y,d) if self.weighted else y)
                        if parents or cycle_detection or subtree_size:
                            ps[y]=x
                        if unweighted_dist or bipartite_graph:
                            uwd[y]=uwd[x]+1
                        if weighted_dist:
                            wd[y]=wd[x]+d
                    elif not finished[y]:
                        if (directed_acyclic or cycle_detection or topological_sort) and dag:
                            dag=False
                            if cycle_detection:
                                cd=(y,x)
            elif not finished[x]:
                finished[x]=True
                if euler_tour:
                    et.append(~x)
                if postorder or topological_sort:
                    post.append(x)
                if subtree_size:
                    for y in self.graph[x]:
                        if self.weighted:
                            y,d=y
                        if y==ps[x]:
                            continue
                        ss[x]+=ss[y]
        if bipartite_graph:
            bg=[[],[]]
            for tpl in self.edges:
                i,j=tpl[:2] if self.weighted else tpl
                if uwd[i]==self.inf or uwd[j]==self.inf:
                    continue
                if not uwd[i]%2^uwd[j]%2:
                    bg=False
                    break
            else:
                for x in range(self.V):
                    if uwd[x]==self.inf:
                        continue
                    bg[uwd[x]%2].append(x)
        retu=()
        if bipartite_graph:
            retu+=(bg,)
        if cycle_detection:
            if dag:
                cd=[]
            else:
                y,x=cd
                cd=self.Route_Restoration(y,x,ps)
            retu+=(cd,)
        if directed_acyclic:
            retu+=(dag,)
        if euler_tour:
            retu+=(et,)
        if linked_components:
            retu+=(lc,)
        if parents:
            retu+=(ps,)
        if postorder:
            retu+=(post,)
        if preorder:
            retu+=(pre,)
        if subtree_size:
            retu+=(ss,)
        if topological_sort:
            if dag:
                tp_sort=post[::-1]
            else:
                tp_sort=[]
            retu+=(tp_sort,)
        if unweighted_dist:
            retu+=(uwd,)
        if weighted_dist:
            retu+=(wd,)
        if len(retu)==1:
            retu=retu[0]
        return retu

    def MIV_DFS(self,initial_vertices=False,bipartite_graph=False,cycle_detection=False,directed_acyclic=False,euler_tour=False,linked_components=False,parents=False,postorder=False,preorder=False,subtree_size=False,topological_sort=False,unweighted_dist=False,weighted_dist=False):
        if not initial_vertices:
            initial_vertices=[s for s in range(self.V)]
        seen=[False]*self.V
        finished=[False]*self.V
        if bipartite_graph:
            bg=[None]*self.V
            cnt=-1
        if directed_acyclic or cycle_detection or topological_sort:
            dag=True
        if euler_tour:
            et=[]
        if linked_components:
            lc=[]
        if parents or cycle_detection or subtree_size:
            ps=[None]*self.V
        if postorder or topological_sort:
            post=[]
        if preorder:
            pre=[]
        if subtree_size:
            ss=[1]*self.V
        if unweighted_dist:
            uwd=[self.inf]*self.V
        if weighted_dist:
            wd=[self.inf]*self.V
        for s in initial_vertices:
            if seen[s]:
                continue
            if bipartite_graph:
                cnt+=1
                bg[s]=(cnt,0)
            if linked_components:
                lc.append([])
            if unweighted_dist:
                uwd[s]=0
            if weighted_dist:
                wd[s]=0
            stack=[(s,0)] if self.weighted else [s]
            while stack:
                if self.weighted:
                    x,d=stack.pop()
                else:
                    x=stack.pop()
                if not seen[x]:
                    seen[x]=True
                    stack.append((x,d) if self.weighted else x)
                    if euler_tour:
                        et.append(x)
                    if linked_components:
                        lc[-1].append(x)
                    if preorder:
                        pre.append(x)
                    for y in self.graph[x]:
                        if self.weighted:
                            y,d=y
                        if not seen[y]:
                            stack.append((y,d) if self.weighted else y)
                            if bipartite_graph:
                                bg[y]=(cnt,bg[x][1]^1)
                            if parents or cycle_detection or subtree_size:
                                ps[y]=x
                            if unweighted_dist or bipartite_graph:
                                uwd[y]=uwd[x]+1
                            if weighted_dist:
                                wd[y]=wd[x]+d
                        elif not finished[y]:
                            if directed_acyclic and dag:
                                dag=False
                                if cycle_detection:
                                    cd=(y,x)
                elif not finished[x]:
                    finished[x]=True
                    if euler_tour:
                        et.append(~x)
                    if postorder or topological_sort:
                        post.append(x)
                    if subtree_size:
                        for y in self.graph[x]:
                            if self.weighted:
                                y,d=y
                            if y==ps[x]:
                                continue
                            ss[x]+=ss[y]
        if bipartite_graph:
            bg_=bg
            bg=[[[],[]] for i in range(cnt+1)]
            for tpl in self.edges:
                i,j=tpl[:2] if self.weighted else tpl
                if not bg_[i][1]^bg_[j][1]:
                    bg[bg_[i][0]]=False
            for x in range(self.V):
                if bg[bg_[x][0]]:
                    bg[bg_[x][0]][bg_[x][1]].append(x)
        retu=()
        if bipartite_graph:
            retu+=(bg,)
        if cycle_detection:
            if dag:
                cd=[]
            else:
                y,x=cd
                cd=self.Route_Restoration(y,x,ps)
            retu+=(cd,)
        if directed_acyclic:
            retu+=(dag,)
        if euler_tour:
            retu+=(et,)
        if linked_components:
            retu+=(lc,)
        if parents:
            retu+=(ps,)
        if postorder:
            retu+=(post,)
        if preorder:
            retu+=(pre,)
        if subtree_size:
            retu+=(ss,)
        if topological_sort:
            if dag:
                tp_sort=post[::-1]
            else:
                tp_sort=[]
            retu+=(tp_sort,)
        if unweighted_dist:
            retu+=(uwd,)
        if weighted_dist:
            retu+=(wd,)
        if len(retu)==1:
            retu=retu[0]
        return retu

    def Tree_Diameter(self,weighted=False):
        def Farthest_Point(u):
            dist=self.SIV_BFS(u,weighted_dist=True) if weighted else self.SIV_BFS(u,unweighted_dist=True)
            fp=0
            for i in range(self.V):
                if dist[fp]<dist[i]:
                    fp=i
            return fp,dist[fp]
        u,d=Farthest_Point(0)
        v,d=Farthest_Point(u)
        return u,v,d

    def SCC(self):
        reverse_graph=[[] for i in range(self.V)]
        for tpl in self.edges:
            i,j=tpl[:2] if self.weighted else tpl
            reverse_graph[j].append(i)
        postorder=self.MIV_DFS(postorder=True)
        scc=[]
        seen=[False]*self.V
        for s in postorder[::-1]:
            if seen[s]:
                continue
            queue=deque([s])
            seen[s]=True
            lst=[]
            while queue:
                x=queue.popleft()
                lst.append(x)
                for y in reverse_graph[x]:
                    if self.weighted:
                        y,d=y
                    if not seen[y]:
                        seen[y]=True
                        queue.append(y)
            scc.append(lst)
        return scc

    def Build_LCA(self,s):
        self.lca_euler_tour,self.lca_parents,depth=self.SIV_DFS(s,euler_tour=True,parents=True,unweighted_dist=True)
        self.lca_dfs_in_index=[None]*self.V
        self.lca_dfs_out_index=[None]*self.V
        for i,x in enumerate(self.lca_euler_tour):
            if x>=0:
                self.lca_dfs_in_index[x]=i
            else:
                self.lca_dfs_out_index[~x]=i
        self.ST=Segment_Tree(2*self.V,lambda x,y:min(x,y),self.V)
        lst=[None]*(2*self.V)
        for i in range(2*self.V-1):
            if self.lca_euler_tour[i]>=0:
                lst[i]=depth[self.lca_euler_tour[i]]
            else:
                lst[i]=depth[self.lca_parents[~self.lca_euler_tour[i]]]
        lst[2*self.V-1]=-1
        self.ST.Build(lst)

    def LCA(self,a,b):
        m=min(self.lca_dfs_in_index[a],self.lca_dfs_in_index[b])
        M=max(self.lca_dfs_in_index[a],self.lca_dfs_in_index[b])
        x=self.lca_euler_tour[self.ST.Fold_Index(m,M+1)]
        if x>=0:
            return x
        else:
            return self.lca_parents[~x]

    def Build_HLD(self,s):
        self.hld_parents,size,self.hld_depth=self.SIV_DFS(s,parents=True,subtree_size=True,unweighted_dist=True)
        stack=[s]
        self.hld_tour=[]
        self.hld_path_parents=[None]*self.V
        self.hld_path_parents[s]=s
        while stack:
            x=stack.pop()
            self.hld_tour.append(x)
            max_size=0
            max_size_y=None
            for y in self.graph[x]:
                if self.weighted:
                    y,d=y
                if y==self.hld_parents[x]:
                    continue
                if max_size<size[y]:
                    max_size=size[y]
                    max_size_y=y
            for y in self.graph[x]:
                if self.weighted:
                    y,d=y
                if y==self.hld_parents[x]:
                    continue
                if y!=max_size_y:
                    stack.append(y)
                    self.hld_path_parents[y]=y
            if max_size_y!=None:
                stack.append(max_size_y)
                self.hld_path_parents[max_size_y]=self.hld_path_parents[x]
        self.hld_tour_idx=[None]*self.V
        for i in range(self.V):
            self.hld_tour_idx[self.hld_tour[i]]=i

    def HLD(self,a,b,edge=False):
        L,R=[],[]
        while self.hld_path_parents[a]!=self.hld_path_parents[b]:
            if self.hld_depth[self.hld_path_parents[a]]<self.hld_depth[self.hld_path_parents[b]]:
                R.append((self.hld_tour_idx[self.hld_path_parents[b]],self.hld_tour_idx[b]+1))
                b=self.hld_parents[self.hld_path_parents[b]]
            else:
                L.append((self.hld_tour_idx[a]+1,self.hld_tour_idx[self.hld_path_parents[a]]))
                a=self.hld_parents[self.hld_path_parents[a]]
        if edge:
            if self.hld_depth[a]!=self.hld_depth[b]:
                retu=L+[(self.hld_tour_idx[a]+1,self.hld_tour_idx[b]+1)]+R[::-1]
            else:
                retu=L+R[::-1]
        else:
            if self.hld_depth[a]<self.hld_depth[b]:
                retu=L+[(self.hld_tour_idx[a],self.hld_tour_idx[b]+1)]+R[::-1]
            else:
                retu=L+[(self.hld_tour_idx[a]+1,self.hld_tour_idx[b])]+R[::-1]
        return retu

    def Build_Hash(self,s,random_number=False,mod=(1<<61)-1,rerooting=False):
        self.bottom_hash=[None]*self.V
        if random_number:
            self.hash_random_number=random_number
        else:
            self.hash_random_number=[random.randint(1,10**10) for i in range(self.V)]
        self.hash_mod=mod
        parents,postorder,preorder=self.SIV_DFS(s,parents=True,postorder=True,preorder=True)
        for x in postorder:
            level=0
            for y in self.graph[x]:
                if self.weighted:
                    y,d=y
                if y==parents[x]:
                    continue
                h,l=self.bottom_hash[y]
                level=max(level,l+1)
            ha=1
            for y in self.graph[x]:
                if self.weighted:
                    y,d=y
                if y==parents[x]:
                    continue
                h,l=self.bottom_hash[y]
                ha*=h+self.hash_random_number[l]
                ha%=self.hash_mod
            self.bottom_hash[x]=(ha,level)
        if rerooting:
            self.top_hash=[None]*self.V
            self.top_hash[s]=(1,-1)
            for x in preorder:
                children=[y for y,d in self.graph[x] if y!=parents[x]] if self.weighted else [y for y in self.graph[x] if y!=parents[x]]
                if children:
                    l=len(children)
                    l_lst,r_lst=[None]*(l+1),[None]*(l+1)
                    l_lst[0],r_lst[l]=(1,-1),(1,-1)
                    for i in range(1,l+1):
                        h0,l0=l_lst[i-1]
                        h1,l1=self.bottom_hash[children[i-1]]
                        l_lst[i]=(h0*(h1+self.hash_random_number[l1])%self.hash_mod,max(l0,l1))
                    for i in range(l-1,-1,-1):
                        h0,l0=r_lst[i+1]
                        h1,l1=self.bottom_hash[children[i]]
                        r_lst[i]=(h0*(h1+self.hash_random_number[l1])%self.hash_mod,max(l0,l1))
                    for i in range(l):
                        if x==s:
                            ha,level=1,0
                        else:
                            ha,level=self.top_hash[x]
                        h0,l0=l_lst[i]
                        h1,l1=r_lst[i+1]
                        ha*=h0*h1
                        level=max(level,l0+1,l1+1)
                        ha+=self.hash_random_number[level]
                        ha%=self.hash_mod
                        level+=1
                        self.top_hash[children[i]]=(ha,level)
        return 

    def Hash(self,root,subtree=False):
        if subtree:
            ha,level=self.bottom_hash[root]
            ha+=self.hash_random_number[level]
            ha%=self.hash_mod
        else:
            h0,l0=self.bottom_hash[root]
            h1,l1=self.top_hash[root]
            ha=(h0*h1+self.hash_random_number[max(l0,l1)])%self.hash_mod
            level=max(l0,l1)
        return ha,level

    def Centroid(self,root=0):
        x=root
        parents,size=self.SIV_DFS(x,parents=True,subtree_size=True)
        while True:
            for y in self.graph[x]:
                if self.weighted:
                    y,d=y
                if y==parents[x]:
                    continue
                if size[y]*2>size[root]:
                    x=y
                    break
            else:
                for y in self.graph[x]:
                    if y==parents[x]:
                        continue
                    if size[root]<=2*size[y]:
                        return x,y
                return x,None

    def Centroid_Decomposition(self,edge=False,linked_point=False,point=False,tree=False):
        if edge:
            cd_edges_lst=[None]*self.V
        if linked_point:
            cd_linked_points=[None]*self.V
        if point:
            cd_points_lst=[None]*self.V
        if tree:
            cd_tree=[]*self.V
        if self.weighted:
            edges=[(i,j) for i,j,d in self.edges]
        else:
            edges=self.edges
        points=[i for i in range(self.V)]
        prev_centroid=None
        stack=[(edges,points,None,prev_centroid)] if linked_point else [(edges,points,prev_centroid)]
        while stack:
            if linked_point:
                edges,points,lp,prev_centroid=stack.pop()
            else:
                edges,points,prev_centroid=stack.pop()
            if len(points)==1:
                centroid=points[0]
                if edge:
                    cd_edges_lst[centroid]=[]
                if linked_point:
                    cd_linked_points[centroid]=lp
                if point:
                    cd_points_lst[centroid]=[centroid]
                if tree and prev_centroid!=None:
                    cd_tree.append((prev_centroid,centroid))
                continue
            G=Graph(len(points),edges=edges)
            centroid,_=G.Centroid()
            if tree and prev_centroid!=None:
                cd_tree.append((prev_centroid,points[centroid]))
            parents,tour=G.SIV_DFS(centroid,parents=True,preorder=True)
            dp=[None]*len(points)
            edges_lst=[]
            points_lst=[]
            if linked_point:
                linked_points=[]
            for i,x in enumerate(G.graph[centroid]):
                dp[x]=(i,0)
                edges_lst.append([])
                points_lst.append([points[x]])
                if linked_point:
                    linked_points.append(points[x])
            for x in tour[1:]:
                for y in G.graph[x]:
                    if y==parents[x]:
                        continue
                    i,j=dp[x]
                    jj=len(points_lst[i])
                    edges_lst[i].append((j,jj))
                    points_lst[i].append(points[y])
                    dp[y]=(i,jj)
            centroid=points[centroid]
            if edge:
                cd_edges_lst[centroid]=edges
            if linked_point:
                cd_linked_points[centroid]=lp
            if point:
                cd_points_lst[centroid]=points
            if linked_point:
                for edges,points,lp in zip(edges_lst,points_lst,linked_points):
                    stack.append((edges,points,lp,centroid))
            else:
                for edges,points in zip(edges_lst,points_lst):
                    stack.append((edges,points,centroid))
        retu=()
        if edge:
            retu+=(cd_edges_lst,)
        if linked_point:
            retu+=(cd_linked_points,)
        if point:
            retu+=(cd_points_lst,)
        if tree:
            retu+=(cd_tree,)
        if len(retu)==1:
            retu=retu[0]
        return retu

    def Distance_Frequency(self):
        mod=206158430209
        cnt=[0]*N
        cd_edges,cd_lp,cd_points,cd_tree=self.Centroid_Decomposition(edge=True,linked_point=True,point=True,tree=True)
        CD=Graph(N,edges=cd_tree)
        parents,tour=CD.SIV_DFS(cd_tree[0][0],parents=True,postorder=True)
        for x in tour:
            C=[0]*(len(cd_points[x])+1)
            for y in CD.graph[x]:
                if y==parents[x]:
                    continue
                for s in range(len(cd_points[y])):
                    if cd_points[y][s]==cd_lp[y]:
                        break
                depth=Graph(len(cd_points[y]),edges=cd_edges[y]).SIV_DFS(s,unweighted_dist=True)
                CC=[0]*(max(depth)+2)
                for d in depth:
                    CC[d+1]+=1
                    cnt[d+1]+=2
                    C[d+1]+=1
                poly=NTT_Pow(CC,2)
                for d,c in enumerate(poly):
                    if d<N:
                        cnt[d]-=c
            while C and C[-1]==0:
                C.pop()
            poly=NTT_Pow(C,2)
            for d,c in enumerate(poly):
                if d<N:
                    cnt[d]+=c
        for i in range(N):
            cnt[i]//=2
        return cnt

    def Dijkstra(self,s,route_restoration=False):
        dist=[self.inf]*self.V
        dist[s]=0
        hq=[(0,s)]
        if route_restoration:
            parents=[None]*self.V
        while hq:
            dx,x=heapq.heappop(hq)
            if dist[x]<dx:
                continue
            for y,dy in self.graph[x]:
                if dist[y]>dx+dy:
                    dist[y]=dx+dy
                    if route_restoration:
                        parents[y]=x
                    heapq.heappush(hq,(dist[y],y))
        if route_restoration:
            return dist,parents
        else:
            return dist

    def Bellman_Ford(self,s,route_restoration=False):
        dist=[self.inf]*self.V
        dist[s]=0
        if route_restoration:
            parents=[None]*self.V
        for _ in range(self.V-1):
            for i,j,d in self.edges:
                if dist[j]>dist[i]+d:
                    dist[j]=dist[i]+d
                    if route_restoration:
                        parents[j]=i
                if not self.directed and dist[i]>dist[j]+d:
                    dist[i]=dist[j]+d
                    if route_restoration:
                        parents[i]=j
        negative_cycle=[]
        for i,j,d in self.edges:
            if dist[j]>dist[i]+d:
                negative_cycle.append(j)
            if not self.directed and dist[i]>dist[j]+d:
                negative_cycle.append(i)
        if negative_cycle:
            is_negative_cycle=[False]*self.V
            for i in negative_cycle:
                if is_negative_cycle[i]:
                    continue
                else:
                    queue=deque([i])
                    is_negative_cycle[i]=True
                    while queue:
                        x=queue.popleft()
                        for y,d in self.graph[x]:
                            if not is_negative_cycle[y]:
                                queue.append(y)
                                is_negative_cycle[y]=True
                                if route_restoration:
                                    parents[y]=x
            for i in range(self.V):
                if is_negative_cycle[i]:
                    dist[i]=-self.inf
        if route_restoration:
            return dist,parents
        else:
            return dist

    def Warshall_Floyd(self,route_restoration=False):
        dist=[[self.inf]*self.V for i in range(self.V)]
        for i in range(self.V):
            dist[i][i]=0
        if route_restoration:
            parents=[[j for j in range(self.V)] for i in range(self.V)]
        for i,j,d in self.edges:
            if i==j:
                continue
            if dist[i][j]>d:
                dist[i][j]=d
                if route_restoration:
                    parents[i][j]=i
            if not self.directed and dist[j][i]>d:
                dist[j][i]=d
                if route_restoration:
                    parents[j][i]=j
        for k in range(self.V):
            for i in range(self.V):
                for j in range(self.V):
                    if dist[i][j]>dist[i][k]+dist[k][j]:
                        dist[i][j]=dist[i][k]+dist[k][j]
                        if route_restoration:
                            parents[i][j]=parents[k][j]
        for i in range(self.V):
            if dist[i][i]<0:
                for j in range(self.V):
                    if dist[i][j]!=self.inf:
                        dist[i][j]=-self.inf
        if route_restoration:
            for i in range(self.V):
                if dist[i][i]==0:
                    parents[i][i]=None
            return dist,parents
        else:
            return dist

    def Route_Restoration(self,s,g,parents):
        route=[g]
        while s!=g:
            if parents[g]==None:
                route=[]
                break
            g=parents[g]
            route.append(g)
        route=route[::-1]
        return route

    def Kruskal(self):
        UF=UnionFind(self.V)
        sorted_edges=sorted(self.edges,key=lambda x:x[2])
        minimum_spnning_tree=[]
        for i,j,d in sorted_edges:
            if not UF.Same(i,j):
                UF.Union(i,j)
                minimum_spnning_tree.append((i,j,d))
        return minimum_spnning_tree

    def Ford_Fulkerson(self,s,t):
        max_flow=0
        residual_graph=[defaultdict(int) for i in range(self.V)]
        if self.weighted:
            for i,j,d in self.edges:
                if not d:
                    continue
                residual_graph[i][j]+=d
                if not self.directed:
                    residual_graph[j][i]+=d
        else:
            for i,j in self.edges:
                residual_graph[i][j]+=1
                if not self.directed:
                    residual_graph[j][i]+=1
        while True:
            parents=[None]*self.V
            parents[s]=s
            seen=[False]*self.V
            seen[s]=True
            queue=deque([s])
            while queue:
                x=queue.popleft()
                for y in residual_graph[x].keys():
                    if not seen[y]:
                        seen[y]=True
                        queue.append(y)
                        parents[y]=x
                        if y==t:
                            tt=t
                            while tt!=s:
                                residual_graph[parents[tt]][tt]-=1
                                residual_graph[tt][parents[tt]]+=1
                                if not residual_graph[parents[tt]][tt]:
                                    residual_graph[parents[tt]].pop(tt)
                                tt=parents[tt]
                            max_flow+=1
                            break
                else:
                    continue
                break
            else:
                break
        return max_flow

    def BFS(self,s):
        seen=[False]*self.V
        seen[s]=True
        queue=deque([s])

        while queue:
            x=queue.popleft()
            for y in self.graph[x]:
                if self.weighted:
                    y,d=y
                if not seen[y]:
                    seen[y]=True
                    queue.append(y)
                    
        return 

    def DFS(self,s):
        seen=[False]*self.V
        finished=[False]*self.V
        stack=[(s,0)] if self.weighted else [s]

        while stack:
            if self.weighted:
                x,d=stack.pop()
            else:
                x=stack.pop()
            if not seen[x]:
                seen[x]=True
                stack.append((x,d) if self.weighted else x)

                for y in self.graph[x]:
                    if self.weighted:
                        y,d=y
                    if not seen[y]:
                        stack.append((y,d) if self.weighted else y)
            elif not finished[x]:
                finished[x]=True
                
        return 

N,M=map(int,readline().split())
edges=[]
for _ in range(N-1):
    a,b=map(int,readline().split())
    a-=1;b-=1
    edges.append((a,b))
G=Graph(N,edges=edges)
cd_edges,cd_lp,cd_points,cd_tree=G.Centroid_Decomposition(edge=True,linked_point=True,point=True,tree=True)
idx=[[] for x in range(N)]
for i in range(N):
    for j,x in enumerate(cd_points[i]):
        idx[x].append((i,j))
cd_G=[Graph(len(cd_points[x]),cd_edges[x]) for x in range(N)]
cd_dist=[cd_G[x].SIV_DFS(cd_points[x].index(x),unweighted_dist=True) for x in range(N)]
cd_sd=[1<<60]*N
for i,j in idx[0]:
    cd_sd[i]=min(cd_sd[i],cd_dist[i][j])
for _ in range(M):
    t,v=map(int,readline().split())
    v-=1
    if t==1:
        for i,j in idx[v]:
            cd_sd[i]=min(cd_sd[i],cd_dist[i][j])
    else:
        ans=1<<60
        for i,j in idx[v]:
            ans=min(ans,cd_sd[i]+cd_dist[i][j])
        print(ans)