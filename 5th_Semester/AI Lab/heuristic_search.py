"""
Informed/ heuristic search
"""

visited = []
import heapq

def best_fast_search(gp,start,goal,heuristic):
    open_set = []
    heapq.heappush(open_set, (heuristic[start], start))
    
    while open_set:
        current_cost , current_node = heapq.heappop(open_set)
        
        if current_node in visited:
            continue
        visited.append(current_node)
        
        if current_node == goal:
            return current_node
        
        for neibor in gp[current_node]:
            if neibor not in visited:
                heapq.heappush(open_set, (heuristic[neibor], neibor))
                
    return None

gp={
    'A':['B','C'],
    'B':['D','E'],
    'C':['F'],
    'D':['G'],
    'E':['G'],
    'F':['G'],
    'G':[]
    }

heuristic={
    'A':6,
    'B':5,
    'C':2,
    'D':1,
    'E':0,
    'F':1,
    'G':0
    }

start_node = 'A'
goal_node = 'G'
result = best_fast_search(gp, start_node, goal_node, heuristic)
print (visited)