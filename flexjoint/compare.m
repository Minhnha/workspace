clc 
clear all
close all
load fjoin.mat
load afile.txt

matlab = fjoin';
cplus = afile;





fontsize = 26;

figure(1)
subplot(2,1,1)
plot(matlab(:,1),matlab(:,2),'b','LineWidth',2,'LineStyle','-');
hold on
plot(cplus(:,1),cplus(:,2),'r','LineWidth',2,'LineStyle','--');
setlabels('Time (s)', 'Rotational angle q_1(rad)', '',[0 4 -0.06 0.1],'on', fontsize);
legend('Matlab','C++');
subplot(2,1,2)
plot(matlab(:,1),matlab(:,2)-cplus(:,2),'b','LineWidth',2,'LineStyle','-');
setlabels('Time (s)', 'Difference q_1(rad)', '',[0 4 -1e-7 1e-7],'on', fontsize);


figure(2)
subplot(2,1,1)
plot(matlab(:,1),matlab(:,3),'b','LineWidth',2,'LineStyle','-');
hold on
plot(cplus(:,1),cplus(:,3),'r','LineWidth',2,'LineStyle','--');
setlabels('Time (s)', 'Rotational angle q_2(rad)', '',[0 4 -20 30],'on', fontsize);
legend('Matlab','C++');
subplot(2,1,2)
plot(matlab(:,1),matlab(:,3)-cplus(:,3),'b','LineWidth',2,'LineStyle','-');
setlabels('Time (s)', 'Difference q_2(rad)', '',[0 4 -1e-4 1e-4],'on', fontsize);


figure(3)
subplot(2,1,1)
plot(matlab(:,1),matlab(:,4),'b','LineWidth',2,'LineStyle','-');
hold on
plot(cplus(:,1),cplus(:,4),'r','LineWidth',2,'LineStyle','--');
setlabels('Time (s)', 'Velocity angle q_1(rad/s)', '',[0 4 -5 5],'on', fontsize);
legend('Matlab','C++');
subplot(2,1,2)
plot(matlab(:,1),matlab(:,4)-cplus(:,4),'b','LineWidth',2,'LineStyle','-');
setlabels('Time (s)', 'Difference velocity q_1(rad/s)', '',[0 4 -1e-5 1e-5],'on', fontsize);


figure(4)
subplot(2,1,1)
plot(matlab(:,1),matlab(:,5),'b','LineWidth',2,'LineStyle','-');
hold on
plot(cplus(:,1),cplus(:,5),'r','LineWidth',2,'LineStyle','--');
setlabels('Time (s)', 'Velocity angle q_2(rad/s)', '',[0 4 -2000 2000],'on', fontsize);
legend('Matlab','C++');
subplot(2,1,2)
plot(matlab(:,1),matlab(:,5)-cplus(:,5),'b','LineWidth',2,'LineStyle','-');
setlabels('Time (s)', 'Difference velocity q_2(rad/s)', '',[0 4 -1e-2 1e-2],'on', fontsize);






% print2word('position q1');
