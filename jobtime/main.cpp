#include <iostream>
#include <vector>
#include <fstream>
#include "timeJob.cpp"

using namespace std;

bool saveJob(vector<timeJob> k){
	ofstream f("job.txt");
	for(int i=0;i<k.size();i++){
	f<<k[i].getStartjob().min<<endl;
	f<<k[i].getStartjob().hour<<endl;
	f<<k[i].getStartjob().day<<endl;
	f<<k[i].getStartjob().mont<<endl;
	f<<k[i].getStartjob().year<<endl;
	f<<k[i].getEndjob().min<<endl;
	f<<k[i].getEndjob().hour<<endl;
	f<<k[i].getEndjob().day<<endl;
	f<<k[i].getEndjob().mont<<endl;
	f<<k[i].getEndjob().year<<endl;
	}
	f.close();
	return true;
}
 
 void loadJob(vector<timeJob> &k){
	int smin, shour, sday, smonth, syear;
	int emin, ehour, eday, emonth, eyear;
	ifstream f("job.txt");
	timeJob tmp;
	int i=0;
	while(!f.eof()){
	f>>smin;
	f>>shour;
	f>>sday;
	f>>smonth;
	f>>syear;
	f>>emin;
	f>>ehour;
	f>>eday;
	f>>emonth;
	f>>eyear;
tmp.setStartJob(smin,shour,sday,smonth,syear);
tmp.setEndJob(emin,ehour,eday,emonth,eyear);
	k.push_back(tmp);
	
	}
	k.erase(k.begin()+i);
	f.close();
	
}

int main(){
	vector <timeJob>v;
	timeJob t;
	int min, hour, day;
	int flag=0;
	loadJob(v);
	do{
	cout<<"вводим? 1/0\n";
	cin>>flag;
	if(flag==0)
	break;
	cout<<"введи час, минуты, день начала\n";
	cin>>hour>>min>>day;
	t.setStartJob(min,hour,day,2,2019);
	cout<<"введи час, минуты, день окончания\n";
	cin>>hour>>min>>day;
	t.setEndJob(min,hour,day,2,2019);
	t.printJob();
	v.push_back(t);
	}
	while(flag);
	saveJob(v);
	v.clear();
	loadJob(v);
	for(int i=0;i<v.size();i++)
	v[i].printJob();
	return 0;

