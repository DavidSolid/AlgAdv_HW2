time_result = read.csv(file="time_result.csv",header = TRUE, sep = ",", dec = ".")
time_result = time_result[order(time_result$NODE),]

held_5 = read.csv(file= "held_5min.csv", header = TRUE, sep = ",", dec = ".")
held_5 = held_5[order(held_5$NODE),]

held_3 = read.csv(file= "held_3min.csv", header = TRUE, sep = ",", dec = ".")
held_3 = held_3[order(held_3$NODE),]

held_1 = read.csv(file= "held_1min.csv", header = TRUE, sep = ",", dec = ".")
held_1 = held_1[order(held_1$NODE),]

held_30 = read.csv(file= "held_30sec.csv", header = TRUE, sep = ",", dec = ".")
held_30 = held_30[order(held_30$NODE),]

held_0 = read.csv(file= "held_0sec.csv", header = TRUE, sep = ",", dec = ".")
held_0 = held_0[order(held_0$NODE),]

err <-data.frame(time_result$NODE, time_result$WEIGHT_2, time_result$WEIGHT_CHEAP, held_5$WEIGHT, held_3$WEIGHT, held_1$WEIGHT, held_30$WEIGHT, held_0$WEIGHT)
isto <-data.frame(time_result$GRAPH, time_result$WEIGHT_2, time_result$WEIGHT_CHEAP, held_5$WEIGHT)


options(scipen=999)

plot(x= held_5$NODE, y= held_5$WEIGHT, log= "xy", type = "l", col= "blue", ylab = "PESO CIRCUITO", xlab = "NUMERO DI NODI", main = "CONFRONTO PESI HELD-KARP 5min", lty = 1, lwd = 2)
plot(x= held_3$NODE, y= held_3$WEIGHT, log= "xy", type = "l", col= "blue", ylab = "PESO CIRCUITO", xlab = "NUMERO DI NODI", main = "CONFRONTO PESI HELD-KARP 3min", lty = 1, lwd = 2)
plot(x= held_1$NODE, y= held_1$WEIGHT, log= "xy", type = "l", col= "blue", ylab = "PESO CIRCUITO", xlab = "NUMERO DI NODI", main = "CONFRONTO PESI HELD-KARP 1min", lty = 1, lwd = 2)
plot(x= held_0$NODE, y= held_0$WEIGHT, log= "xy", type = "l", col= "blue", ylab = "PESO CIRCUITO", xlab = "NUMERO DI NODI", main = "CONFRONTO PESI HELD-KARP 0sec", lty = 1, lwd = 2)

# lines(x = held_3$NODES, y = held_3$WEIGHT, col= "green", lty = 1, lwd = 2)
# lines(x = held_1$NODES, y = held_1$WEIGHT, col= "red", lty = 1, lwd = 2)
# lines(x = held_30$NODES, y = held_30$WEIGHT, col= "violet", lty = 1, lwd = 2)
# lines(x = held_5$NODES, y = held_0$WEIGHT, col= "brown", lty = 1, lwd = 2)



# plot(x = me$NODES, y = me$BFS, log = "xy", type = "l", col= "blue", ylab = "TEMPO DI ESECUZIONE (s)", xlab = "NUMERO DI NODI", main = "CONFRONTO TEMPI MEDI DEGLI ALGORITMI PER NUMERO DI NODI", lty = 1, lwd = 2)
# lines(x = me$NODES, y = me$`UNION-FIND`, col= "green", lty = 1, lwd = 2)
# lines(x = me$NODES, y = me$PRIM,col="red", lty = 1, lwd = 2)
# lines(x = me$NODES, y = me$DFS,col="violet", lty = 1, lwd = 2)
# 
# points(x = me$NODES, y = me$DFS, pch= 15, col="violet", cex=0.85)
# points(x = me$NODES, y = me$BFS, pch= 16, col="blue", cex=0.85)
# points(x = me$NODES, y = me$`UNION-FIND`, pch= 17, col="green", cex=0.85)
# points(x = me$NODES, y = me$PRIM, pch= 18, col="red", cex=0.85)
# legend(legend=c("BFS", "DFS", "UNION-FIND", "PRIM"), col=c("blue", "violet", "green", "red"), title="Algoritmo", text.font=4, "topleft", lty= 1, lwd = 2)
# 
# plot(x = me$NODES, y = me$BFS, log = "x", type = "l", col= "blue", ylab = "TEMPO DI ESECUZIONE (s)", xlab = "NUMERO DI NODI", main = "CONFRONTO TEMPI MEDI KRUSKAL DFS / BFS", lty = 1, lwd = 2)
# lines(x = me$NODES, y = me$DFS,col="violet", lty = 1, lwd = 2)
# points(x = me$NODES, y = me$DFS, pch= 15, col="violet", cex=0.85)
# points(x = me$NODES, y = me$BFS, pch= 16, col="blue", cex=0.85)
# legend(legend=c("BFS", "DFS"),
#        col=c("blue", "violet"), title="Algoritmo", text.font=4, "topleft", lty= 1, lwd = 2)
# 
# plot(x = me$NODES, y = me$PRIM, log = "x", type = "l", col= "red", ylab = "TEMPO DI ESECUZIONE (s)", xlab = "NUMERO DI NODI", main = "CONFRONTO TEMPI MEDI PRIM / UNION-FIND", lty = 1, lwd = 2)
# lines(x = me$NODES, y = me$`UNION-FIND`,col="green", lty = 1, lwd = 2)
# points(x = me$NODES, y = me$`UNION-FIND`, pch= 17, col="green", cex=0.85)
# points(x = me$NODES, y = me$PRIM, pch= 18, col="red", cex=0.85)
# legend(legend=c("UNION-FIND", "PRIM"),
#        col=c("green", "red"), title="Algoritmo", text.font=4, "topleft", lty= 1, lwd = 2)




plot(x= time_result$NODE, y= time_result$TIME_CHEAP,xaxt="n",log= "xy", type = "l", col= "blue", ylab = "TEMPO ESECUZIONE", xlab = "NUMERO DI NODI", main = "CONFRONTO 2-APPROX e CHEAPEST INSERT", lty = 1, lwd = 2)
lines(x= time_result$NODE, y= time_result$TIME_2,col="red", lty = 1, lwd = 2)

points(x = time_result$NODE, y = time_result$TIME_CHEAP, pch= 0, col="blue", cex=0.85)
points(x = time_result$NODE, y = time_result$TIME_2, pch= 5, col="red", cex=0.85)
legend(legend=c("CHEAPEST INSERTION", "2-APPROSSIMAZIONE"),
       col=c("blue", "red"), title="Algoritmo", text.font=4, "topleft", lty= 1, lwd = 2)
axis(1,at=held_5$NODE,labels = held_1$NODE, las=2)

giusto <-data.frame(time_result$NODE)
giusto$WEIGHT = c(3323, 6859, 7013, 426, 7542, 21294, 21282, 6528, 40160, 134602, 50778, 35002, 18659688)

relative <-data.frame(err$time_result.NODE, (err$time_result.WEIGHT_2 - giusto$WEIGHT)/giusto$WEIGHT, (err$time_result.WEIGHT_CHEAP - giusto$WEIGHT)/giusto$WEIGHT, (err$held_5.WEIGHT - giusto$WEIGHT)/giusto$WEIGHT, (err$held_3.WEIGHT - giusto$WEIGHT)/giusto$WEIGHT, (err$held_1.WEIGHT - giusto$WEIGHT)/giusto$WEIGHT, (err$held_30.WEIGHT - giusto$WEIGHT)/giusto$WEIGHT, (err$held_0.WEIGHT - giusto$WEIGHT)/giusto$WEIGHT)
colnames(relative) <- c("NODE", "WEIGHT_2", "WEIGHT_CHEAP", "HELD_5", "HELD_3", "HELD_1", "HELD_30", "HELD_0")


plot(x= relative$NODE, y= relative$HELD_5,xaxt="n",log= "xy", type = "l", col= "blue", ylab = "ERRORE RELATIVO", xlab = "NUMERO DI NODI", main = "CONFRONTO ERRORI RELATIVI", lty = 1, lwd = 2)
lines(x= relative$NODE, y= relative$WEIGHT_2,col="red", lty = 1, lwd = 2)
lines(x= relative$NODE, y= relative$WEIGHT_CHEAP,col="green", lty = 1, lwd = 2)
points(x = relative$NODE, y = relative$HELD_5, pch= 0, col="blue", cex=0.85)
points(x = relative$NODE, y = relative$WEIGHT_2, pch= 0, col="red", cex=0.85)
points(x = relative$NODE, y = relative$WEIGHT_CHEAP, pch= 0, col="green", cex=0.85)
# lines(x= relative$NODE, y= relative$HELD_3,col="red", lty = 1, lwd = 2)
# lines(x= relative$NODE, y= relative$HELD_1,col="green", lty = 1, lwd = 2)
# lines(x= relative$NODE, y= relative$HELD_30,col="yellow", lty = 1, lwd = 2)
# lines(x= relative$NODE, y= relative$HELD_0,col="violet", lty = 1, lwd = 2)
legend(legend=c("HELD-KARP", "2-APPROSSIMAZIONE", "CHEAPEST INSERTION"),
       col=c("blue", "red", "green"), title="Algoritmo", text.font=4, "topleft", lty= 1, lwd = 2)
axis(1,at=relative$NODE,labels = relative$NODE, las=2)



tempo <-data.frame(c(300,180,60,30,0),c(mean(relative$HELD_5), mean(relative$HELD_3),mean(relative$HELD_1),mean(relative$HELD_30),mean(relative$HELD_0)))
colnames(tempo) <- c("TIMEOUT", "MEDIA")
plot(x= tempo$TIMEOUT, y= tempo$MEDIA,xaxt="n", type = "l",log= "y")
points(x = tempo$TIMEOUT, y = tempo$MEDIA, pch= 0, col="blue", cex=0.85)
axis(1,at=tempo$TIMEOUT,labels = tempo$TIMEOUT, las=2)



