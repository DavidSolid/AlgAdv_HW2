time_result = read.csv(file="time_result.csv",header = TRUE, sep = ",", dec = ".")
time_result = time_result[order(time_result$NODE),]

held_20 = read.csv(file= "held_20min.csv", header = TRUE, sep = ",", dec = ".")
held_20 = held_20[order(held_20$NODE),]

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

err <-data.frame(time_result$NODE, time_result$WEIGHT_2, time_result$WEIGHT_CHEAP, held_20$WEIGHT, held_5$WEIGHT, held_3$WEIGHT, held_1$WEIGHT, held_30$WEIGHT, held_0$WEIGHT)


options(scipen=999)

# plot(x= held_5$NODE, y= held_5$WEIGHT, log= "xy", type = "l", col= "blue", ylab = "PESO CIRCUITO", xlab = "NUMERO DI NODI", main = "CONFRONTO PESI HELD-KARP 5min", lty = 1, lwd = 2)
# plot(x= held_3$NODE, y= held_3$WEIGHT, log= "xy", type = "l", col= "blue", ylab = "PESO CIRCUITO", xlab = "NUMERO DI NODI", main = "CONFRONTO PESI HELD-KARP 3min", lty = 1, lwd = 2)
# plot(x= held_1$NODE, y= held_1$WEIGHT, log= "xy", type = "l", col= "blue", ylab = "PESO CIRCUITO", xlab = "NUMERO DI NODI", main = "CONFRONTO PESI HELD-KARP 1min", lty = 1, lwd = 2)
# plot(x= held_0$NODE, y= held_0$WEIGHT, log= "xy", type = "l", col= "blue", ylab = "PESO CIRCUITO", xlab = "NUMERO DI NODI", main = "CONFRONTO PESI HELD-KARP 0sec", lty = 1, lwd = 2)

# lines(x = held_3$NODES, y = held_3$WEIGHT, col= "green", lty = 1, lwd = 2)
# lines(x = held_1$NODES, y = held_1$WEIGHT, col= "red", lty = 1, lwd = 2)
# lines(x = held_30$NODES, y = held_30$WEIGHT, col= "violet", lty = 1, lwd = 2)
# lines(x = held_5$NODES, y = held_0$WEIGHT, col= "brown", lty = 1, lwd = 2)


plot(x= time_result$NODE, y= time_result$TIME_CHEAP,xaxt="n",log= "xy", type = "l", col= "blue", ylab = "TEMPO ESECUZIONE", xlab = "NUMERO DI NODI", main = "CONFRONTO 2-APPROX e CHEAPEST INSERT", lty = 1, lwd = 2)
lines(x= time_result$NODE, y= time_result$TIME_2,col="red", lty = 1, lwd = 2)

points(x = time_result$NODE, y = time_result$TIME_CHEAP, pch= 0, col="blue", cex=0.85)
points(x = time_result$NODE, y = time_result$TIME_2, pch= 5, col="red", cex=0.85)
legend(legend=c("CHEAPEST INSERTION", "2-APPROSSIMAZIONE"),
       col=c("blue", "red"), title="Algoritmo", text.font=4, "topleft", lty= 1, lwd = 2)
axis(1,at=held_5$NODE,labels = held_1$NODE, las=2)

giusto <-data.frame(time_result$NODE)
giusto$WEIGHT = c(3323, 6859, 7013, 426, 7542, 21294, 21282, 6528, 40160, 134602, 50778, 35002, 18659688)

relative <-data.frame(err$time_result.NODE, (err$time_result.WEIGHT_2 - giusto$WEIGHT)/giusto$WEIGHT, (err$time_result.WEIGHT_CHEAP - giusto$WEIGHT)/giusto$WEIGHT, (err$held_20.WEIGHT - giusto$WEIGHT)/giusto$WEIGHT, (err$held_5.WEIGHT - giusto$WEIGHT)/giusto$WEIGHT, (err$held_3.WEIGHT - giusto$WEIGHT)/giusto$WEIGHT, (err$held_1.WEIGHT - giusto$WEIGHT)/giusto$WEIGHT, (err$held_30.WEIGHT - giusto$WEIGHT)/giusto$WEIGHT, (err$held_0.WEIGHT - giusto$WEIGHT)/giusto$WEIGHT)
colnames(relative) <- c("NODE", "WEIGHT_2", "WEIGHT_CHEAP", "HELD_20", "HELD_5", "HELD_3", "HELD_1", "HELD_30", "HELD_0")


plot(x= relative$NODE, y= relative$HELD_20,xaxt="n",log= "xy", type = "l", col= "blue", ylab = "ERRORE RELATIVO", xlab = "NUMERO DI NODI", main = "CONFRONTO ERRORI RELATIVI", lty = 1, lwd = 2)
lines(x= relative$NODE, y= relative$WEIGHT_2,col="red", lty = 1, lwd = 2)
lines(x= relative$NODE, y= relative$WEIGHT_CHEAP,col="green", lty = 1, lwd = 2)
points(x = relative$NODE, y = relative$HELD_20, pch= 0, col="blue", cex=0.85)
points(x = relative$NODE, y = relative$WEIGHT_2, pch= 0, col="red", cex=0.85)
points(x = relative$NODE, y = relative$WEIGHT_CHEAP, pch= 0, col="green", cex=0.85)
# lines(x= relative$NODE, y= relative$HELD_3,col="red", lty = 1, lwd = 2)
# lines(x= relative$NODE, y= relative$HELD_1,col="green", lty = 1, lwd = 2)
# lines(x= relative$NODE, y= relative$HELD_30,col="yellow", lty = 1, lwd = 2)
# lines(x= relative$NODE, y= relative$HELD_0,col="violet", lty = 1, lwd = 2)
legend(legend=c("HELD-KARP", "2-APPROSSIMAZIONE", "CHEAPEST INSERTION"),
       col=c("blue", "red", "green"), title="Algoritmo", text.font=4, "topleft", lty= 1, lwd = 2)
axis(1,at=relative$NODE,labels = relative$NODE, las=2)



tempo <-data.frame(c(1200,300,180,60,30,0),c(mean(relative$HELD_20), mean(relative$HELD_5), mean(relative$HELD_3),mean(relative$HELD_1),mean(relative$HELD_30),mean(relative$HELD_0)))
colnames(tempo) <- c("TIMEOUT", "MEDIA")
plot(x= tempo$TIMEOUT, y= tempo$MEDIA,xaxt="n", type = "l",log= "y", col= "blue", ylab = "MEDIA ERRORI RELATIVI", xlab = "TIMEOUT (S)", main = "CONFRONTO MEDIA ERRORI RELATIVI AL VARIARE DEL TIMEOUT", lty = 1, lwd = 2)
points(x = tempo$TIMEOUT, y = tempo$MEDIA, pch= 0, col="blue", cex=0.85)
axis(1,at=tempo$TIMEOUT,labels = tempo$TIMEOUT, las=2)

#da non fare mai ma non posso far girare il programma per altre 9 ore solo per dei tempi che differiscono per qualche secondo se non millisecondo
held_20$TIME = c(2.44453,	14.64750, 900 + 302.14300, 900 + 300.66200, 900 + 300.64700, 900 + 300.24300, 900 + 300.23500, 900 + 300.12100, 900 + 300.07100, 900 + 300.068, 900 + 300.188, 900 + 300.234, 900 + 301.523)

tabella <-data.frame(time_result$GRAPH, held_20$WEIGHT, held_20$TIME, relative$HELD_20, time_result$WEIGHT_CHEAP, time_result$TIME_CHEAP, relative$WEIGHT_CHEAP, time_result$WEIGHT_2, time_result$TIME_2, relative$WEIGHT_2)
colnames(tabella) = c("Istanza", "Soluzione", "Tempo (s)", "Errore", "Soluzione", "Tempo (s)", "Errore", "Soluzione", "Tempo (s)", "Errore")
write.csv(tabella, "tabella.csv", row.names = TRUE, quote = FALSE)




options(scipen=10)
options(digits=2)
#sono pigro
stime <-data.frame(held_20$GRAPH, held_20$NODE)
colnames(stime) = c("GRAPH", "NODE")
stime$DIM = (2^(stime$NODE - 2) -1 ) * (stime$NODE - 1) + 1
stime$TIME = stime$DIM * ((5.5)*(10^(-5)))
write.csv(stime, "stime.csv", row.names = TRUE, quote = FALSE)

par(mar=c(4.1, 2.1, 2.1, 10.1))
plot(x= stime$NODE, y= stime$TIME,xaxt="n",log= "xy",yaxt="n",type = "l", col= "green", ylab = "", xlab = "NUMERO DI NODI", main = "CRESCITA DEL TEMPO STIMATO AL CRESCERE DEI NODI", lty = 1, lwd = 2)

points(x= stime$NODE, y= stime$TIME, pch= 0, col="blue", cex=0.85)
title(ylab = "TEMPO STIMATO (s)", line = 1)
axis(1,at=stime$NODE,labels = stime$NODE, las=2,)

axis(4,at=stime$TIME,labels = stime$TIME, las=2, cex.axis=0.65)


