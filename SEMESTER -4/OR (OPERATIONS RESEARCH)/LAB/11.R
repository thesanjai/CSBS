library(igraph)
nodes=c("1","2","3","4","5")
edges=matrix(c(1,2,1,3,2,4,2,5,3,4,4,5),ncol=2,byrow=TRUE)
ec=c(8,4,10,2,5,3)
g=graph_from_edgelist(edges,directed = TRUE)
plot(g,layout=layout_nicely(g),vertex.label=nodes,vertex.size=50)

pp=all_simple_paths(g,from = 1, to =5)

calculate_path_value <- function(path) {
  total_duration <- 0
  for (i in 1:(length(path) - 1)) {
    edge <- c(path[i], path[i + 1])
    total_duration <- total_duration + ec[which(edges[,1] == edge[1] &
                                                              edges[,2] == edge[2])]
    
  }
  return(total_duration)
}
path_values <- sapply(pp, calculate_path_value)
paths_and_values <- data.frame(Path = sapply(pp, function(path)paste(nodes[path], collapse = " -> ")), Value = path_values)
print(paths_and_values)
x

