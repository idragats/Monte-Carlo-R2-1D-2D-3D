file1=load("randomWalk1d.txt");
file2=load("randomWalk2d.txt");
file3=load("randomWalk3d.txt");

x1=file1(:,1);
y1=file1(:,2);

x2=file2(:,1);
y2=file2(:,2);

x3=file3(:,1);
y3=file3(:,2);

figure(1)
p1 = polyfit(x1,y1,1); 
f1 = polyval(p1,x1); 

p2 = polyfit(x2,y2,1); 
f2 = polyval(p2,x2); 

p3 = polyfit(x3,y3,1); 
f3 = polyval(p3,x3); 

figure(1)
clf;
plot(x1,y1,'o',x1,f1,'-') 
legend('data',['Line Equation is y = ',num2str(p1(1)),'*x + ','(',num2str(p1(2)),')'],'Location','northwest')  
xlabel("N")
ylabel("<R^2>")
title("1D")





figure(2)
clf;
plot(x2,y2,'o',x2,f2,'-')
legend('data',['Line Equation is y = ',num2str(p2(1)),'*x + ','(',num2str(p2(2)),')'],'Location','northwest') 
xlabel("N")
ylabel("<R^2>")
title("2D")


figure(3)
clf;
plot(x3,y3,'o',x3,f3,'-')
legend('data',['Line Equation is y = ',num2str(p3(1)),'*x + ','(',num2str(p3(2)),')'],'Location','northwest') 
xlabel("N")
ylabel("< R^2 >")
title("3D")




