class Graph(object):
    def __init__(self, graph_dict ={}):
        self.__graph_dict = graph_dict
    def vertices(self):
        return list(self.__graph_dict.keys())
    def edges(self):
        return self.__gen_edges()
    
    def add_vertex(self, vertex):
        if vertex not in self.__graph_dict:
            self.__graph_dict[vertex] = []
            #new a list to store related edges
        else:
            print "vertex has already exist!"
            
    def add_edge(self, edge):
        edge = set(edge)
        (vertex1, vertex2) = tuple(edge)
        if vertex1 in self.__graph_dict:
            self.__graph_dict[vertex1].append(vertex2)
        else:
            self.__graph_dict[vertex1] = [vertex2]
    def __gen_edges(self):
        edges = []
        for vertex in self.__graph_dict:
            for neighbour in self.__graph_dict[vertex]:
                if {neighbour, vertex} not in edges:
                    edges.append({vertex, neighbour})
        return edges
    def __str__(self):
        res = "vertices: "
        for k in self.__graph_dict:
            res += str(k) + " "
        res += "\n edges: "
        for edge in self.__gen_edges():
            res += str(edge) + " "
        return res
        
    def findpath(self, start_v,end_v, path = []):
        graph = self.__graph_dict
        path = path + [start_v]
        if start_v == end_v:
            return path
        if start_v not in graph:
            return None
        for neighbour in graph[start_v]: #find near nodes
            if neighbour not in path:
                extended_path = self.findpath(neighbour, end_v, path)
                if extended_path != None:
                    return extended_path
        return None
    
    def find_all_paths(self, start_vertex, end_vertex, path=[]):
        """ find all paths from start_vertex to 
            end_vertex in graph """
        graph = self.__graph_dict 
        path = path + [start_vertex]
        if start_vertex == end_vertex:
            return [path]
        if start_vertex not in graph:
            return []
        paths = []
        for vertex in graph[start_vertex]:
            if vertex not in path:
                extended_paths = self.find_all_paths(vertex, end_vertex, path)
                for p in extended_paths: 
                    paths.append(p)
        return paths
        
    def vertex_degree(self, vertex):
        adj_vertices = self.__graph_dict[vertex]
        degree = len(adj_vertices) + adj_vertices.count(vertex)
        return degree
    def find_isolated_vertices(self):
        """ returns a list of isolated vertices. """
        graph = self.__graph_dict
        isolated = []
        for vertex in graph:
            print(isolated, vertex)
            if not graph[vertex]:
                isolated += [vertex]
        return isolated
    def degree_sequence(self):
        seq = []
        for vertex in self.__graph_dict:
            seq.append(self.vertex_degree(vertex))
        seq.sort(reverse = True)
        return tuple(seq)
    def is_connected(self, vertices_encountered = set(), start_v =None):
        graph_dict = self.__graph_dict
        vertices = graph_dict.keys()
        if not start_v:
            start_v = graph_dict[0]
        
        vertices_encountered.add(start_v)
        if len(vertices_encountered) != len(vertices):
            for vertex in graph_dict[start_v]:
                if vertex not in vertices_encountered:
                    if self.is_connected(vertices_encountered, vertex):
                        return True
        else: #if the same mean all connected
            return True
        return False
    def diameter(self):
        """ calculates the diameter of the graph """
        
        v = self.vertices() 
        pairs = [ (v[i],v[j]) for i in range(len(v)) for j in range(i+1, len(v)-1)]
        smallest_paths = []
        for (s,e) in pairs:
            paths = self.find_all_paths(s,e)
            smallest = sorted(paths, key=len)[0]
            smallest_paths.append(smallest)

        smallest_paths.sort(key=len)

        # longest path is at the end of list, 
        # i.e. diameter corresponds to the length of this path
        diameter = len(smallest_paths[-1])
        return diameter        
        
if __name__ == "__main__":
    g = { "a" : ["c"],
        "b" : ["c","e","f"],
        "c" : ["a","b","d","e"],
        "d" : ["c"],
        "e" : ["b","c","f"],
        "f" : ["b","e"]
    }
    
    
    graph = Graph(g)
    
    diameter = graph.diameter()
    
    print(diameter)     