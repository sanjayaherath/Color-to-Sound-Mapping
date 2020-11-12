%data preparation

Red     = [ [855 855 854 854 854 853 853 853 853 853 852 853 853 853 853 ] ;
[815 815 814 814 814 814 814 814 814 814 814 814 815 814 814 ];
[917 916 916 916 915 915 916 916 916 916 916 916 916 917 917 ] ]';

Blue       = [[1004 1002 1002 1001 1001 1001 1001 1001 1001 1001 1001 1002 1001 1001 1002 ] ;
[849 849 848 847 846 846 846 846 846 846 846 845 845 845 845 ] ;
[841 841 840 840 840 840 840 840 839 839 839 840 839 839 839 ] ]';

Violet = [[914 914 914 913 913 914 913 913 913 913 913 913 913 913 913 ]; 
[841 841 840 840 841 841 841 841 841 841 841 841 841 841 841 ]; 
[866 864 863 864 864 864 864 864 864 864 864 864 864 864 864  ]]';

Orange      = [[844 844 844 844 844 844 844 844 844 844 845 845 844 845 844 ] ;
[689 689 689 688 688 688 689 688 689 689 689 689 689 689 689 ] ;
[922 922 922 922 922 922 922 922 922 923 922 922 922 922 922 ] ]';

Green     = [[976 976 976 976 976 976 976 976 976 976 976 975 976 976 976 ] ;
[636 636 636 635 635 636 635 635 635 636 635 635 635 636 635 ] ;
[873 873 873 872 873 873 872 873 873 873 872 873 873 873 873 ] ]';

Yellow        = [[838 837 837 837 838 838 838 838 838 838 838 838 838 838 838 ] ;
[530 528 528 528 528 529 529 529 529 529 529 529 529 530 529 ] ;
[913 913 913 913 913 913 913 913 913 913 913 913 913 913 913 ] ]';

Cyan     = [[973 972 973 973 973 973 973 973 973 973 973 973 973 973 973 ] ;
[625 625 624 624 624 624 623 623 623 624 624 624 624 624 624 ] ;
[779 779 778 779 778 779 778 779 778 778 779 778 778 779 778 ] ]';

Black     = [[1015 1014 1014 1016 1018 1016 1019 1016 1019 1014 1018 1014 1017 1014 1017 ] ;
[917 916 916 936 937 942 942 943 944 934 934 931 932 930 931 ] ;
[960 959 959 969 969 972 972 973 974 968 968 967 967 966 966 ] ]'; 

Total_Data = [Red;  Blue; Violet; Orange;  Green; Yellow; Cyan;Black];
Data=Red;
Data(:,:,2)=Blue;
Data(:,:,3)=Violet;
Data(:,:,4)=Orange;
Data(:,:,5)=Green;
Data(:,:,6)=Yellow;
Data(:,:,7)=Cyan;
Data(:,:,8)=Black;

% fischer analysis

no_classes = 8;
no_dimension = 3;

%classwise mean
classwise_mean=mean(Data);
%total mean
total_mean=mean(Total_Data);

Sb=[0 0 0;0 0 0; 0 0 0];
for i=1:8
    u=classwise_mean(:,:,i)-total_mean;
    Sb=Sb+ 15*(u'*u);
end

Sw=[0 0 0;0 0 0; 0 0 0];
for i=1:8
   Sw=Sw+ 15*cov(Data(:,:,i)) ;
end

eigval=eig(Sw\Sb);
display(eigval);

[eigvec,V]=eig(Sw\Sb);

%obtain the corresponding vector of highest eigenval
bigvec=eigvec(:,1);
projected_Data=[];
for i=1:8
    x=bigvec'*Data(:,:,i)';
    projected_Data=[projected_Data; x];
end    
x=[0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ];
hold on;
scatter(projected_Data(1,:),x,'filled','r');
scatter(projected_Data(2,:),x,'filled','b');
scatter(projected_Data(3,:),x,'filled','m');
scatter(projected_Data(4,:),x,'k');
scatter(projected_Data(5,:),x,'filled','g');
scatter(projected_Data(6,:),x,'filled','y');
scatter(projected_Data(7,:),x,'filled','c');
scatter(projected_Data(8,:),x,'filled','k');


mean_proj=mean(projected_Data');
std_proj=std(projected_Data');
