#ifndef TIMEJOB_H
#define TIMEJOB_H
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
	
	public:
	bool setStartJob(int min, int hour, int day, int month, int year);
	bool setEndJob(int min, int hour, int day, int month, int year);
	
};
#endif TIMEJOB_H