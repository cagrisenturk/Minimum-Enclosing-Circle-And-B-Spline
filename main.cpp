#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>

#define XAXIS 760
#define YAXIS 760
#define SCALE 19

void coordinate_plane(){ //DRAWING THE COORDINATE PLANE
	
	setcolor(WHITE);
    line(XAXIS/2,0,XAXIS/2,YAXIS);
    
    setcolor(WHITE);
    line(0,YAXIS/2,XAXIS,YAXIS/2);
    
	for(int i=0;i<41;i++){ 
	setcolor(WHITE);
	 line((XAXIS/2)-5,i*SCALE,(XAXIS/2)+5,i*SCALE);
	}	
	
	for(int i=0;i<41;i++){ 
	setcolor(WHITE);
	 line(i*SCALE,(YAXIS/2)+5,i*SCALE,(YAXIS/2)-5);
	}
	
	int j=0;
	int i=-20;
	char assignment[50];

	for(i=-20;i<21;i++){ 
	
		sprintf(assignment,"%d ",i);
		settextstyle(SMALL_FONT,HORIZ_DIR,5);
		outtextxy(j*SCALE,(YAXIS/2)+5,assignment);
		j++; 
	}

	j=0;
	for(i=20;i>-21;i--){
		
		if(i==0){ 
			
			j++;
		}	
		else{	
		sprintf(assignment,"%d ",i);
		settextstyle(SMALL_FONT,HORIZ_DIR,5);
		outtextxy((XAXIS/2)+5,j*SCALE,assignment);
		j++; }
	}		
}

void drawdot(int coordinatexy[100][2],int draw_coordinate,int coordinatecenterx,int coordinatecentery){ //PLACING OUR COORDINATES ON THE COORDINATE PLANE
	for(int i=0;i<draw_coordinate;i++)
	{
	setcolor(RED);
    setfillstyle(1, RED);
    fillellipse(coordinatecenterx+(SCALE*coordinatexy[i][0]),coordinatecentery-(SCALE*coordinatexy[i][1]),3,3);
}

}

double distance(double x1, double y1) {
	double find_distance=(x1*x1)+(y1*y1);
	return find_distance;
}
void drawcircle(double circlex,double circley,double circleradius,int coordinateplanex,int coordinateplaney) //DRAWING THE SMALLEST CIRCLE INCLUDING ALL COORDINATES
{
	setcolor(WHITE);
    circle(coordinateplanex+(circlex*SCALE),coordinateplaney-(circley*SCALE),circleradius*SCALE);
}
void drawradiusandcenterpoint(double circlex,double circley,double circleradius,int coordinateplanex,int coordinateplaney) //DRAWING THE CIRCLE'S RADIUS AND CENTER POINT
{
	setcolor(BLUE);
    setfillstyle(1, BLUE);
    fillellipse(coordinateplanex+(SCALE*circlex),coordinateplaney-(SCALE*circley),3,3);
    setcolor(YELLOW);
    line(coordinateplanex+(SCALE*circlex),coordinateplaney-(SCALE*circley),coordinateplanex+(SCALE*circlex),coordinateplaney-(SCALE*circley)+circleradius*SCALE);
}


void buble_sort(int coordinate[100][2],int coordinateamount) //SORTING THE COORDINATES ACCORDING TO X-AXIS
{
int i,j,tmp;
for(i=0; i<coordinateamount-1; i++) {
for(j=0; j<coordinateamount-1-i; j++) {
if(coordinate[j][0]>coordinate[j+1][0]){
tmp=coordinate[j][0];
coordinate[j][0]=coordinate[j+1][0];
coordinate[j+1][0]=tmp;
tmp=coordinate[j][1];
coordinate[j][1]=coordinate[j+1][1];
coordinate[j+1][1]=tmp;
}
}
}}



void bsp(int dot[4][2], int process,double splinex [1001],double spliney [1001]) //MULTIPLYING MATRICES FROM MULTIPLY MATRICES.PNG
        {
            double a [5] ;
            double b [5] ;
            
            a[0] = (-dot[0][0] + 3 * dot[1][0] - 3 * dot[2][0] + dot[3][0]) / 6.0;   
            a[1] = (3 * dot[0][0] - 6 * dot[1][0] + 3 * dot[2][0]) / 6.0;
            a[2] = (-3 * dot[0][0] + 3 * dot[2][0]) / 6.0;
            a[3] = (dot[0][0] + 4 * dot[1][0] + dot[2][0]) / 6.0;
            b[0] = (-dot[0][1] + 3 * dot[1][1] - 3 * dot[2][1] + dot[3][1]) / 6.0; 
            b[1] = (3 * dot[0][1] - 6 * dot[1][1] + 3 * dot[2][1]) / 6.0;
            b[2] = (-3 * dot[0][1] + 3 * dot[2][1]) / 6.0;
            b[3] = (dot[0][1] + 4 * dot[1][1] + dot[2][1]) / 6.0;
            splinex[0] = a[3];  
            spliney[0] = b[3];

            int i;
            for (i = 1; i <= process -1; i++)
            {                 
             float  t = ((float)i / (float)process);  
			
             splinex[i] =  (a[2] + t * (a[1] + t * a[0]))*t+a[3]  ;  
             spliney[i] =    (b[2] + t * (b[1] + t * b[0]))*t+b[3] ; 
            }
        }





void drawbspline(int coordinate[100][2],int coordinate_amount,int coordinateplanex,int coordinateplaney) //DRAWING BSPLINE CURVE
        {
        double splinex [1001];
        double spliney [1001];
        coordinate[coordinate_amount][0]=coordinate[coordinate_amount-1][0];
        coordinate[coordinate_amount][1]=coordinate[coordinate_amount-1][1];
        int dot[4][2];
        int control = 0;

            for (int i = 0; i <=coordinate_amount; i++)
            {
                int dotX = coordinate[i][0];
                int dotY = coordinate[i][1];
                if (control > 3)
                {					
                    dot[0][0] = dot[1][0];dot[1][0] = dot[2][0];dot[2][0] = dot[3][0];
                    dot[0][1] = dot[1][1];dot[1][1] = dot[2][1];dot[2][1] = dot[3][1];
                    dot[3][0]=dotX;  
					dot[3][1]=dotY;
                    double distance = sqrt(pow(dot[2][0] - dot[1][0], 2) + pow(dot[2][1] - dot[1][1], 2));
					
                    int process = distance*SCALE;
                    bsp(dot,process,splinex,spliney);
                    double x,y;
                    setcolor(BLUE);
                    setlinestyle(0, 0, 4);
                    
                    for (int j = 0; j <= process - 1; j++)
                    {
                    	
                        x=coordinateplanex+(SCALE*splinex[j]);
                        y=coordinateplaney-(SCALE*spliney[j]);
						         
                        line(x - 1, y, x + 1, y);
                        line( x, y - 1, x, y + 1);

                               
                    }				
                } 	
                	
				
                else
                {
                	for(int k=0;k<4;k++){
                    dot[k][0]=dotX;
                    dot[k][1]=dotY;
                    
					control = control + 1; }
                }				
                	
            }
        }





int main(int argc, char** argv) {
   
   FILE *file;
	
	char curlybracesandcomma[2][4];
	int coordinate[100][2];
	int i=0;
	int coordinate_amount = 0;
	file= fopen("coordinate.txt","r");
	if((file= fopen("coordinate.txt","r"))!=NULL) {
		while(!feof(file)){
			fscanf(file,"%c%d%c%d%c%c",&curlybracesandcomma[0][0],&coordinate[i][0],&curlybracesandcomma[0][1],&coordinate[i][1],&curlybracesandcomma[0][2],&curlybracesandcomma[0][3]);
			printf("%d . Coordinate : %d , %d \n",i+1,coordinate[i][0],coordinate[i][1]);
			i++;	
			coordinate_amount++;	
		}		
	}
	else {
		printf("File Not Found!");
		exit(0);	
	}
	for(int j=0;j<coordinate_amount;j++)
	{
		if(coordinate[j][0]>20 ||coordinate[j][0]<-20 || coordinate[j][1]>20 ||coordinate[j][1]<-20)
		{
				printf("Coordinates aren't look well please check ");
				exit(0);
		}
	}
	fclose(file);
	buble_sort(coordinate,coordinate_amount);
	initwindow(XAXIS+25,YAXIS+25, "COORDINATE PLANE");
    int coordinateplanex=XAXIS/2;
    int coordinateplaney=YAXIS/2;
	coordinate_plane();
	drawdot(coordinate,coordinate_amount,coordinateplanex,coordinateplaney);


	double Xpoints,Ypoints; //FINDING THE SMALLEST CIRCLE INCLUDING ALL COORDINATES
	double k,l;
	for(int i=0;i<coordinate_amount;i++)
	{
	Xpoints=Xpoints+coordinate[i][0];
	Ypoints=Ypoints+coordinate[i][1];	
	}
	Xpoints=Xpoints/coordinate_amount;
	Ypoints=Ypoints/coordinate_amount;
	double P = 0.1;
	for (int m=0;m<10000;m++) { 
		int f = 0;
		k = distance(Xpoints-coordinate[0][0],Ypoints-coordinate[0][1]);
		for (int n=1;n<coordinate_amount; n++) {
			l = distance(Xpoints-coordinate[n][0], Ypoints - coordinate[n][1]);
			if (k<l) {
			k = l;
			f = n; 
			}
		}
		Xpoints =Xpoints+((coordinate[f][0] - Xpoints)*P); 
		Ypoints =Ypoints+((coordinate[f][1]- Ypoints)*P);
		P =P* 0.999;
}
	printf("\n ----The Smallest Circle Including All Coordinates's----\n");
    printf("Center Point = %.3lf %.3lf\nRadius = %.3lf", Xpoints, Ypoints, sqrt(k));
    double circlex=Xpoints;
    double circley=Ypoints;
    double circleradius=sqrt(k);
    drawcircle(circlex,circley,circleradius,coordinateplanex,coordinateplaney);
    drawradiusandcenterpoint(circlex,circley,circleradius,coordinateplanex,coordinateplaney);
 	drawbspline(coordinate,coordinate_amount,coordinateplanex,coordinateplaney);
 
    getch();
    closegraph();	
	return 0;
}
