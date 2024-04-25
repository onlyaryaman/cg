#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
int xmin, xmax, ymin, ymax;


struct lines {
	int x1, y1, x2, y2;
};


int sign(int x)
{
	if (x > 0)
		return 1;
	else
		return 0;
}


void clip(struct lines mylines)
{
	
	int bits[4], byte[4], i, var;
	
	setcolor(RED);
	bits[0] = sign(xmin - mylines.x1);
	byte[0] = sign(xmin - mylines.x2);
	bits[1] = sign(mylines.x1 - xmax);
	byte[1] = sign(mylines.x2 - xmax);
	bits[2] = sign(ymin - mylines.y1);
	byte[2] = sign(ymin - mylines.y2);
	bits[3] = sign(mylines.y1 - ymax);
	byte[3] = sign(mylines.y2 - ymax);

	
	string initial = "", end = "", temp = "";

	
	for (i = 0; i < 4; i++) {
		if (bits[i] == 0)
			initial += '0';
		else
			initial += '1';
	}
	for (i = 0; i < 4; i++) {
		if (byte[i] == 0)
			end += '0';
		else
			end += '1';
	}

	

	float m = (mylines.y2 - mylines.y1) / (float)(mylines.x2 - mylines.x1);
	float c = mylines.y1 - m * mylines.x1;

	
	if (initial == end && end == "0000") {
		
		line(mylines.x1, mylines.y1, mylines.x2, mylines.y2);
		return;
	}

	
	else {
		
		for (i = 0; i < 4; i++) {

			int val = (bits[i] & byte[i]);
			if (val == 0)
				temp += '0';
			else
				temp += '1';
		}
		if (temp != "0000")
			return;

		for (i = 0; i < 4; i++) {

			if (bits[i] == byte[i])
				continue;
		
			if (i == 0 && bits[i] == 1) {
				var = round(m * xmin + c);
				mylines.y1 = var;
				mylines.x1 = xmin;
			}
			// Case when final point is in left xmin
			if (i == 0 && byte[i] == 1) {
				var = round(m * xmin + c);
				mylines.y2 = var;
				mylines.x2 = xmin;
			}
			// Case when initial point is in right of xmax
			if (i == 1 && bits[i] == 1) {
				var = round(m * xmax + c);
				mylines.y1 = var;
				mylines.x1 = xmax;
			}
			// Case when final point is in right of xmax
			if (i == 1 && byte[i] == 1) {
				var = round(m * xmax + c);
				mylines.y2 = var;
				mylines.x2 = xmax;
			}
			// Case when initial point is in top of ymin
			if (i == 2 && bits[i] == 1) {
				var = round((float)(ymin - c) / m);
				mylines.y1 = ymin;
				mylines.x1 = var;
			}
			// Case when final point is in top of ymin
			if (i == 2 && byte[i] == 1) {
				var = round((float)(ymin - c) / m);
				mylines.y2 = ymin;
				mylines.x2 = var;
			}
			// Case when initial point is in bottom of ymax
			if (i == 3 && bits[i] == 1) {
				var = round((float)(ymax - c) / m);
				mylines.y1 = ymax;
				mylines.x1 = var;
			}
			// Case when final point is in bottom of ymax
			if (i == 3 && byte[i] == 1) {
				var = round((float)(ymax - c) / m);
				mylines.y2 = ymax;
				mylines.x2 = var;
			}
			// Updating Bits at every point
			bits[0] = sign(xmin - mylines.x1);
			byte[0] = sign(xmin - mylines.x2);
			bits[1] = sign(mylines.x1 - xmax);
			byte[1] = sign(mylines.x2 - xmax);
			bits[2] = sign(ymin - mylines.y1);
			byte[2] = sign(ymin - mylines.y2);
			bits[3] = sign(mylines.y1 - ymax);
			byte[3] = sign(mylines.y2 - ymax);
		} 
		initial = "", end = "";
		for (i = 0; i < 4; i++) {
			if (bits[i] == 0)
				initial += '0';
			else
				initial += '1';
		}
		for (i = 0; i < 4; i++) {
			if (byte[i] == 0)
				end += '0';
			else
				end += '1';
		}
		
		if (initial == end && end == "0000") {
			line(mylines.x1, mylines.y1, mylines.x2, mylines.y2);
			return;
		}
		else
			return;
	}
}


int main()
{
	int gd = DETECT, gm;

	
    
	xmin = 40;
	xmax = 100;
	ymin = 40;
	ymax = 80;
    cout<<"Enter the coordinate of the window xmin, xmax, ymin and ymax"<<endl;
    cin>>xmin;
    cin>>xmax;
    cin>>ymin;
    cin>>ymax;

	
	initgraph(&gd, &gm, NULL);

	
	line(xmin, ymin, xmax, ymin);
	line(xmax, ymin, xmax, ymax);
	line(xmax, ymax, xmin, ymax);
	line(xmin, ymax, xmin, ymin);

	
	struct lines mylines[4];

	
	mylines[0].x1 = 30;
	mylines[0].y1 = 65;
	mylines[0].x2 = 55;
	mylines[0].y2 = 30;
    cout<<"Enter the start and end coordinates of the line x1, y1, x2, y2"<<endl;
    cin>>mylines[0].x1;
	cin>>mylines[0].y1;
	cin>>mylines[0].x2;
	cin>>mylines[0].y2;

	mylines[1].x1 = 60;
	mylines[1].y1 = 20;
	mylines[1].x2 = 100;
	mylines[1].y2 = 90;

	mylines[2].x1 = 60;
	mylines[2].y1 = 100;
	mylines[2].x2 = 80;
	mylines[2].y2 = 70;

	mylines[3].x1 = 85;
	mylines[3].y1 = 50;
	mylines[3].x2 = 120;
	mylines[3].y2 = 75;

	
	for (int i = 0; i < 1; i++) {
		line(mylines[i].x1, mylines[i].y1,
			mylines[i].x2, mylines[i].y2);
		delay(1000);
	}

	
	for (int i = 0; i < 1; i++) {
		
		clip(mylines[i]);
		delay(1000);
	}
	delay(4000);
	getch();
	// For Closing the graph.
	closegraph();
	return 0;
}
