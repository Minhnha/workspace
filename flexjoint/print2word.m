function [] = print2word(name_of_figure)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
cd Figures
set(gcf, 'PaperPositionMode', 'auto');
print('-depsc','-r300',[num2str(name_of_figure),'_eps']);   % for PDF creater
print('-dmeta','-r300',[num2str(name_of_figure),'_emf']);  % for Word preview
print('-dtiff','-r300',[num2str(name_of_figure),'_tif']);  % for study review
cd ..

end

