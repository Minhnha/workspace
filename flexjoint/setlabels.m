function [] = setlabels(label_x,label_y,title_top,set_axis,xy_grid,fontsize)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

xlabel(label_x,'FontName','Times New Roman','Fontsize',fontsize,'FontWeight','Normal');
ylabel(label_y,'FontName','Times New Roman','Fontsize',fontsize,'FontWeight','Normal');
title(title_top,'FontName','Times New Roman','Fontsize',fontsize,'FontWeight','Normal');
set(gca,'FontName','Times New Roman','Fontsize',fontsize,'FontWeight','normal','LineWidth',1);
axis(set_axis);
set(gca,'XGrid',xy_grid,'YGrid',xy_grid,'ZGrid',xy_grid);
end


