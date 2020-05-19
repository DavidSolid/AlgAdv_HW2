time_result = read.csv(file="time_result.csv",header = TRUE,sep = ',')
held = read.csv(file= "held_5min.csv", header = TRUE,sep=',')
held$NODE=c(52,14,150,493,1000,51,202,229,100,100,442,16,22)
time_result$NODE=c(52,14,150,493,1000,51,202,229,100,100,442,16,22)
