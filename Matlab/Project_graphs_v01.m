%% MatLab Simulation Code
% *COMS2004 Assignment 1*  
% Group D
% Tyson Cross: 
% Student No. 1239448. 
% Last edited 2016/08/15
% _Electrical Engineering
% Wits University, 2016_ 
%% Cleanup
clf; clc; clear(); close('all')

format short g

filename = '../Products/Debug/output.txt';
delimiterIn = ' ';
headerlinesIn = 1;
Data = importdata(filename,delimiterIn,headerlinesIn);

for k = [1 2 3 4]
   input  = (Data.data(:, 1))
   brute  = (Data.data(:, 2))
   divide = (Data.data(:, 3))
   kadane = (Data.data(:, 4))
end

%input = logspace(0, 3, 301)

grey = [0.45 0.45 0.45, 0.75];
red = [1.0 0.0 0.0, 0.75];
blue = [0.0 1.0 0.0, 0.75];
green = [0.0 0.0 1.0, 0.75];


%% Axes and Figure
scrnsz = get(groot,'ScreenSize') ;
scrn_x = 2000 ;
scrn_y = 1800 ;

% Create figure
figure1 = figure('Renderer','opengl','PaperOrientation','landscape','Position',[(scrnsz(3)/2-scrn_x/2)...
    (scrnsz(4)/2-scrn_y/2) scrn_x scrn_y],'inverthardcopy','off','color','w') ;
orient landscape

% Create axes
ax1 = axes('position', [0.03 0.042 .96 .9],'Parent',figure1,'LineWidth',1,...
    'FontSize',12,'FontName','Helvetica Neue','Box','off')


%% Curve Fitting


%% Curves


p1 = loglog(brute,'-','Parent',ax1','LineWidth',1,'color', red,'DisplayName','Brute Force');
hold on
p2 = loglog(divide,'-','Parent',ax1','LineWidth',1,'color', blue,'DisplayName','Divide and Conquer');
hold on
p3 = loglog(kadane,'-','Parent',ax1','LineWidth',1,'color', green,'DisplayName','Kadanes Algorithm');
hold on
% Plot fit with data.
% h1 = plot(fitresult);
% set(h1,'LineStyle','-','color','k','LineWidth',2,'Parent',ax3,'DisplayName','B=B') ;

%% determine position of the axes
axp = get(ax1,'Position');

ylabel('Time [\mus] \rightarrow') ;% y-axis label
xlabel('Input Array Size [# elements] \rightarrow') ;% x-axis label

%ax1.XTickLabelRotation=45;
%ax1.YTickLabelRotation=45;

% Set the axis limits
% axis([0.0 input(end) 0.0 brute(end)])

hold(ax1,'all');
%% Titles
ttl={'Algorithm performance vs input size'};
%txt= text(max_x/2, max_y*1.03, ttl,'Interpreter','tex');



%% Create legend

% get the handles for children of the axes -- these are the data series handles
plot_list = get(ax1, 'Children')
% generate a legend command using these "children"
legend1 = legend(plot_list)

legend('show');
set(legend1,...
    'Position',[0.2 0.6 0.05 0.05]);
set(legend1,'FontSize',14','FontName','Helvetica Neue', 'box','off');

%close figure 1;