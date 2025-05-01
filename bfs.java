import java.io.*;
import java.util.*;
import java.util.Scanner.*;


class Graph<T>{
    private Map<T, List<T>> map = new HashMap<>();
    public void addVertex(T s) {
        map.put(s, new LinkedList<T>());
    }
    public void addEdge(T source, T des) {
        // source if doesnt exist 
        if(!map.containsKey(source)) addVertex(source);
        // add des if doesnt exist 
        if(!map.containsKey(des)) addVertex(des);
        // get the source and add the des to the hash map
        map.get(source).add(des);
        map.get(des).add(source);
    }
    public boolean hasNeighbour(T node) {
        return map.containsKey(node) && !map.get(node).isEmpty();
    }
    public Map<T, Integer> bfs(T start) {
        Map<T, Integer> dist = new HashMap<>();
        
        for (T node : map.keySet()) { // fill up the array
            dist.put(node, -1);
        } 
        
        dist.put(start , 0);
        Queue<T> q = new LinkedList<>(); // init linked list and hashset
        Set<T> s = new HashSet<>();
        
        q.add(start); 
        s.add(start); 
        
        while(!q.isEmpty()) {
            T node = q.poll();
            
            for(T neigh : map.getOrDefault(node, new ArrayList<>())) {
                if(!s.contains(neigh)) {
                    s.add(neigh); 
                    dist.put(neigh, dist.get(node) + 6);  // Each edge has weight of 6
                    q.add(neigh);
                }
            }
        }
        return dist;
    }
}

public class Solution {
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        
        while(q-- > 0) {
            int nodeCount = scanner.nextInt();
            int edgeCount = scanner.nextInt();
            
            Graph<Integer> graph = new Graph<Integer>();
            
            for(int i = 0; i < edgeCount; i++) {
                int nodeVal = scanner.nextInt();
                int nodeNeighbour = scanner.nextInt();
                graph.addEdge(nodeVal, nodeNeighbour);
            }
            
            int start = scanner.nextInt();
            Map<Integer, Integer> dist = graph.bfs(start);
            
            for (int i = 1; i <= nodeCount; i++) {
                if (i == start) continue;  // Skip the start node
                if(dist.get(i) == null) System.out.print("-1 "); 
                else System.out.print(dist.get(i) + " ");  // Print distance from the map
            }
            System.out.println();
        }
    }
}
