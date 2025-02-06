#dfs

# def dfs(grp,st,visit=None):
#     if visit is None:
#         visit = set()
    
#     visit.add(st)
        
#     print(st)
        
#     for next in grp[st]-visit:
#         dfs(grp,next,visit)
            
#     return visit

# grp={'0':set(['1','2']),
#      '1':set(['0', '3', '4' ]),
#      '2':set(['0']),
#      '3':set(['1']),
#      '4':set(['2','3'])}

# dfs(grp,'0')

graph = {
'A': ['B', 'C'],
'B': ['D', 'E'],
'C': ['F'],
'D': [],
'E': ['F'],
'F': []
}#dictionary

visited = set()

def dfs(graph, vertex):
    visited.add(vertex)
    print(vertex, end=" ")

    for neighbor in graph[vertex]:
        if neighbor not in visited:
            dfs(graph, neighbor)

# Starting DFS from vertex 'A'
dfs(graph, 'A')