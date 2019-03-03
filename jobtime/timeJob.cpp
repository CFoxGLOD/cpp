#include <iostream>
using namespace std;
struct sTime{
	int min;
	int hour;
	int day;
	int mont;
	int year;
};


class timeJob{
	private:
	sTime startjob;
	sTime endjob;
	bool update(sTime time){
		if(time.min>59){
		cout<<"ты мудило у тебя "<<time.min<<" минут ты на какой планете живешь гандон блять"<<endl;
		return false;
		}
				if(time.hour>23){
		cout<<"ты мудило у тебя "<<time.hour<<" часов ты на какой планете живешь гандон блять"<<endl;
		return false;
		}
				if(time.day>31){
		cout<<"ты мудило у тебя "<<time.day<<" дней ты на какой планете живешь гандон блять"<<endl;
		return false;
		}
				if(time.mont>12){
		cout<<"ты мудило у тебя "<<time.mont<<" месяцев ты на какой планете живешь гандон блять"<<endl;
		return false;
		}
				if(time.year>2020){
		cout<<"ты мудило у тебя "<<time.year<<" год ты на какой планете живешь гандон блять"<<endl;
		return false;
		}
		return true;
	}
	
	public:
	bool setStartJob(int min, int hour, int day, int month, int year){
		startjob.min=min;
		startjob.hour=hour;
		startjob.day=day;
		startjob.mont=month;
		startjob.year=year;
		
		return update(startjob);
		}
	bool setEndJob(int min, int hour, int day, int month, int year){
		endjob.min=min;
		endjob.hour=hour;
		endjob.day=day;
		endjob.mont=month;
		endjob.year=year;
		return update(endjob);
		}
		void printJob(){
			cout<<"начало "<<startjob.hour<<":"<<startjob.min;
			cout<<" конец "<<endjob.hour<<":"<<endjob.min<<endl;
			timeDiff();
			
		}
		sTime getStartjob(){
			return startjob;
		}
		sTime getEndjob(){
			return endjob;
		}
		
		void timeDiff(){
			int dhour,dmin;
			/*endjob.year-startjob.year;
			endjob.mont-startjob.mont;
			endjob.day-startjob.day;*/
			if(endjob.hour-startjob.hour<0)
	dhour=(24-startjob.hour)+endjob.hour;
	//else
	dhour=endjob.hour-startjob.hour;
			
	if(endjob.min-startjob.min<0)
	dmin=(60-startjob.min)+endjob.min;
	//else
	dmin=endjob.min-startjob.min;
	
	cout<<"итого "<<dhour<<" часов "<<dmin<<" минут"<<endl;
		}
};