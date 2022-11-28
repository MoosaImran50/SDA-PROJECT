#include <iostream>
#include "myconsole.h"
#include "mygraphics.h"
#include <Windows.h>
#include <string>
#include <conio.h>
using namespace std;

class user
{
	string uname;
	int id;
	string upass;
	string uemail;
	int points;
	string *maintenanceHistory;
	double mileage;
	double dailyAvg;
	string date;
	string number;
	int expenditure;
public:
	void viewDashboard();
	void bookAppointment();
	void updateMileage();
};

class cashier
{
	string cname;
	string cpass;
public:
	cashier(string cname, string cpass)
	{
		//cout<<"Cashier created"<<endl;
	};
	int recordService(int userId,string userDetail);
};

class staff
{
	string sname;
	int jobsdone;
	int id;
	string spass;
	int leaves;
	int staffType;
public:
	void requestLeave(string leaveRequestArr[]);
};

class floorManager
{
	string fname;
	string femail;
	string fpass;
public:
	floorManager(string fname, string femail, string fpass)
	{
		//cout<<"Floor Manager created"<<endl;
	};
	void checkJobs(int upcomingWorkArr[]);
	void checkPerformance();
	void returnItem(string item);
	void viewStaff(staff staffobjArr[]);
};

class workshopManager
{
	string wname;
	string wemail;
	string wpass;
public:
	workshopManager(string wname, string wemail, string wpass)
	{
		//cout<<"Workshop Manager created"<<endl;
	};
	void manageShifts(int upcomingWorkArr[]);
	void updateLeaveQuotas();
	void handleMaintenanceSchedule();
	void approveLeaves(string leaveReqArr[]);
	int predictJobLoad();
	void viewReports();
};

class workshop
{
	workshopManager WMObj;
public:
	workshop(string wname, string wemail, string wpass): WMObj(wname,wemail,wpass)
	{
		//cout<<"Workshop created"<<endl;
	};
};

class inventoryManager
{
	string name;
	string email;
	int id;
	string pass;
public:
	void allocateInventory(int id);
	void updateReorderLevel(int id);
	void checkStockLevel(int id);
};

class inventory
{
	int stockLevel;
	int reorderLevel;
	int tyres;
	int suspensionKits;
	int windscreens;
	int bumpers;
	int sideMirrors;
	int rims;
public:
	inventory(int stockLevel, int reorderLevel, int tyres, int suspensionKits, int windscreens, int bumpers, int sideMirrors, int rims)
	{
		//cout<<"Inventory created"<<endl;
	};
};

class outlet
{
	int outletId;
	string location;
	inventory iObj;
	workshop wObj;
	floorManager fmObj;
	staff* sObj;
	cashier cObj;
	int status;
public:
	outlet(int outletId, string location, int stockLevel, int reorderLevel, int tyres, int suspensionKits, int windscreens, int bumpers, int sideMirrors, int rims, string wname, string wemail, string wpass, string fname, string femail, string fpass, string cname, string cpass): iObj(stockLevel, reorderLevel, tyres, suspensionKits, windscreens, bumpers, sideMirrors, rims), wObj(wname, wemail, wpass), fmObj(fname, femail, fpass), cObj(cname, cpass)
	{
		//cout<<"Outlet Created"<<endl;
	};
};

class outletAdmin
{
	string oname;
	string oemail;
	string opass;
public:
	outlet* createOutlet(int id)
	{
		//outlet outletObj();
		//return &outletObj;
	};
	void updateOutlet(int id);
	void deleteOutlet(int id);
	void blockOutlet(int id);
	void transferStaff();
	void deactivateAccount(int userId);
	void addInventoryParts();
	void updateWorkingSchedules();
};

void drawcarmenu(int x,int y,int carcolor)	//This function draws the menu where we have to choose our taxi color
{
	COLORREF black = RGB(50,50,50);
	COLORREF tcolor;

	if(carcolor==1)
		tcolor = RGB (29,104,142);		//Chooses yellow color for taxi
	else if(carcolor==2)
		tcolor = RGB (200,0,0);			//Chooses red color for car

	myRect(x-50,y-25,x+50,y+25,tcolor,tcolor);		//Draws upper half of car
	myRect(x-100,y,x+100,y+50,tcolor,tcolor);		//Draws lower half of car
	myEllipse(x-55,y+40,x-20,y+75,black,black);		//Draws left tyre of car
	myEllipse(x+20,y+40,x+55,y+75,black,black);		//Draws right tyre of car
}

int main()
{
	COLORREF grey = RGB(128,128,128);
	COLORREF white = RGB(255,255,255);
	COLORREF black = RGB(00,00,00);
	COLORREF text = RGB(64,128,128);
	COLORREF darkgrey = RGB(50,50,50);
	COLORREF green = RGB(0,204,0);
	COLORREF peach = RGB(255,178,102);
	COLORREF yellow = RGB (255,255,0);
	COLORREF red = RGB(255,0,0);
	COLORREF manag = RGB(255,155,0);
	COLORREF custom = RGB(250,65,0);


	for(int i=0;i<200;i=i+2)
	{
		COLORREF grey = RGB(i,i,i);
		myDrawTextWithFont(220,140,150," SJ Motors ",black,grey);
		Sleep(50);
	}

	drawcarmenu(110,200,1);
	drawcarmenu(850,200,2);

	myDrawText(400,450,10,"Press any key to continue",white,black);
	_getch();
	myDrawText(400,450,10,"Press any key to continue",black,black);
	myDrawTextWithFont(0,140,300," SJ Motors ",black,black);


	outletAdmin OAobj;			//Creating outlet admin
	inventoryManager IMobj;		//Creating inventory manager
	outlet* outletArr;			//Creating outlet array which will be filled by outletadmin upon calling createOutlet function

	//outletArr=OAobj.createOutlet(1);

	int option;

	myDrawTextWithFont(170,0,50,"------ Welcome to SJ Motor System ------",black,white);
	Sleep(2000);

	myDrawTextWithFont(10,70,30,"Select customer or management:",white,black);
	myDrawTextWithFont(10,100,30,"1-Customer",custom,black);
	myDrawTextWithFont(10,130,30,"2-Management",manag,black);


	cin>>option;
	system("CLS");
	if(option==2)
	{
		myDrawTextWithFont(10,40,40,"----Enter a number----",white,black);
		myDrawTextWithFont(10,100,30,"1-Outlet Admin",manag,black);
		myDrawTextWithFont(10,130,30,"2-Inventory Manager",manag,black);
		myDrawTextWithFont(10,160,30,"3-Workshop Manager",manag,black);
		myDrawTextWithFont(10,190,30,"4-Floor Manager",manag,black);
		myDrawTextWithFont(10,220,30,"5-Staff",manag,black);
		myDrawTextWithFont(10,250,30,"6-Cashier",manag,black);
	}
	else 
	{
		myDrawTextWithFont(240,0,50,"------ Customer Sign In ------",black,white);
	}
	getch();
	system("pause");
}