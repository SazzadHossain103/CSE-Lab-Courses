#BFS

g={5:[6,7],
   6:[8,9],
   7:[10,11],
   8:[12],
   9:[],
   10:[],
   11:[],
   12:[]}

def bfsAlgo(g,s):
    v=[]
    q=[]
    v.append(s)
    q.append(s)
    
    while q:
        value=q.pop(0)
        print(value,end=" ")
        for x in g[value]:
            if x not in v:
                v.append(x)
                q.append(x)
                
bfsAlgo(g,5)

