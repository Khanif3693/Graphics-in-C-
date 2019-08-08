/***********************************************************************
** Program Filename: Assignmnent6 code
** Author: Sanchit Chopra
** Date: 17/03/2019
** Description: This program is mainly showing the heat transfer of wire or a plate. The program will be asking all the information needed for the heat transfer and either it 	  for wire or plate, then finally telling the heat transfer to the user.
** Input: The program gets all the information needed for the heat transfer from the user.
** Output: The program will finally produce the heat transfer for wire or plate depemding upon the user input.
************************************************************************/ 

#include<iostream>
#include<cmath>
#include<cstring>
#include<stdlib.h>
#include<limits>
using namespace std;

/***********************************************************************
** Function Name: verifyNum
** Description: This function verify the input by the user is an integer or not.
** Parameter: var.
** input: We pass the input by the user to this function.
** Output: Exit the program if the user input is not an integer.
***********************************************************************/ 

char verifyNum(char *var){
	bool error = false;
	for(int i =0;i < strlen(var);i++){
		if(var[i] != '.' && !(var[i] >='0' && var[i] <='9')){		//Check the user if the input is an integer or not.
			error = true;
			break;	
		}	
	}
	return !error;
}

/*********************************************************************
** Function Name: verufyStr
** Description: This function verify the input by the user is a string or not.
** Paramters: var.
** Input: We pass the input by the user to this function.
** Output: Exit the program if the user input is not a string.
*********************************************************************/ 

char verifyStr(char *var){
	bool error = false;	
	for(int i =0; i < strlen(var) ; i++){
		if(var[i] == '.' && (var[i] <= '0' && var[i] >= '9')){		//Check the user if the input is a string or not.
			error = true;
			break;	
		}	
	}
	return !error;
}

/*************************
** Function Name: verify.
** Parameters: var.
** Description: This function verify the input by the user is a valid or not.
** Input: We pass the input by the user to this function.
** Output: Exit the program if the user input is valud or not.
*************************/

float verify(string var){
	bool error = false;
	float  n =0;
	for(int i =0;i<var.length();i++){
		if(var.at(i) != '.' && !(var.at(i) >='0' && var.at(i)<='9')){		//Check the user if the input is valid.
			cout<<"Invalid Input!!!"<<endl;
			error = true;
			break;	
		}	
	}
	if(error){
		cout<<"Enter that again: ";		//Asking again for input.
		cin>>var;	
		return verify(var);		//Checking again the input.
	}
	n = atof(var.c_str());
	return n;
			
} 

/********************************************************************
** Function Name: processParams
** Descrption: This function get all the arguments that the user pass int the command line and modify all those value.
** Parameters: argc, argv, rho, k, c.
** Input: The program get all the command line argimunts that user input.
** Output: The program will modify all the values for specific constants and pass those constants to rest of the program.
********************************************************************/

char* processParams(int argc, char** argv, float &rho, float &k, float &c){
	char *type;
	int u_count=1,r_count=1,k_count=1,c_count=1;
	for(int i = 1;i< argc;i +=2){	
		
		if(u_count == 1 && verifyStr(argv[i+1]) && strcmp(argv[i], "-u") == 0){		//Getting the value of u, verify it and checking that it is just 1 time.
			int n = strlen(argv[i+1]);
			type = new char[n];
			type = argv[i+1];
			u_count--;
		}
		else if(r_count == 1 && verifyNum(argv[i+1]) && strcmp(argv[i], "-r")==0){	//Getting the value of r, verify it and checking that it is just 1 time.
			rho = atof(argv[i+1]);
			r_count--;	
		}
		else if(k_count == 1 && verifyNum(argv[i+1]) && strcmp(argv[i], "-k") == 0){	//Getting the value of k, verify it and checking that it is just 1 time.
			k = atof(argv[i+1]);
			k_count--;
		}
		else if(c_count == 1 && verifyNum(argv[i+1]) && strcmp(argv[i], "-c") == 0){	//Getting the value of c, verify it and checking that it is just 1 time.
			c = atof(argv[i+1]);
			c_count--;
		}
		else{  // if the user repeat the paramter or put integer instead of string or vice-versa.
			cout<<"Please check your paramenters!!! You must have entered same parameter two times or any other parameter which was not need..."<<endl;
			exit(0);	
		}
	}
	return type;
}

/************************************************
** Function Name: Modify
** Desciption: The program will ask the user to modify the constants if the user did not pass the constants in the command line arguments.
** Paramter:  k, c, rho.
** Input: In this function the user inputs the value they want to modify.
** Output: Passes those values to the rest of the code.
************************************************/ 

float Modify(float &k,float &c,float &rho){ 
		cout<<"What will be the k: ";
		cin>>k;  //Getting k from the user if they want to modify.
		cout<<"What will be the c: ";
		cin>>c; //Getting c from the user if they want to modify. 
		cout<<" What will br the rho: ";
		cin>>rho; //Getting rho from the user if they want to modify.	
}

/************************************************
** Function Name: WireDimesion 
** Description: This program is asking the user to input all the dimensions for the wire if the user wants to see the diffusion of wire and then passing those to the other       function which will be calsulating teh heat diffusion for it.
** Parameter: length, sections, time, itime, k, c, rho, right, left, intial, dx,dt. 
** Input: In this function the user inputs all the dimmensions of the wire.
** Output: This function passess all the dimension to the other function which will calculate the diffusion.
************************************************/ 

void WireDimension(float &length,int  &sections,double  &time,int  &itime,float &k,float &rho,float &c,float &right,float &left,float &intial,float &dx,float &dt){
	string  l=" ", s=" ", i=" ", t=" ", r=" ",le=" ", in=" ";
	cout<<"Enter the length of the wire:";
	cin>>l;	//Getting length from the user for wire.
	length = verify(l);//verifying it.
	cout<<"Enter the sections of wire: ";
	cin>>s;	//Getting sections from the user for wire.
	sections = verify(s);//verifying.
	dx = length/sections; 	//Calculating dx for the equation that calculate the heat diffusion.
	cout<<"For how many time intervals you want the Diffusion: ";
	cin>>i;	//Getting the time interval from the user for wire.
	itime = verify(i);//verifying
	cout<<"Fow how much time you want to stimulate: ";
	cin>>t;	//Getting the time from the user for wire.
	time = verify(t);//verifying.
	cout<<"Enter the right temperature: ";
	cin>>r;	//Getting the right temperature from the user 
	right = verify(r);//verifyinh.
	cout<<"Enter the left temperature: ";
	cin>>le;;	//Getting the left temperature from the user.
	left = verify(le);//verifying.
	cout<<"Enter the intial temperature: ";
	cin>>in;	//Getting the intial temperature from the user.
	intial = verify(in);//verifying.
	dt = time/itime;
}
/***************************
** Function Name: delete_array1
** Paramters: u,itime,sections
** Description: This function mainly get the array and  deallocate the array from heap.
** Input: We pass the array into this function.
** Output: This function deallocate from heap.
***************************/ 

void delete_array1(float **u,int itime,int sections){
	for(int i =0;i< itime;i++){
			delete[] u[i];	
	}	
	delete[] u;
}

/********************************************************
** Function Name: WireDiffusion
** Description: This function gets all the dimesnions from the other function if the user wants to calculate for wire and calculate the diffusion for the it.
** Parameter: length, sections, time, itime, k, rho, c, right, left, intial, dx ,dt.
** Input: We passes all the dimensions we get from the user to this function.
** Output: Calculate the diffusion for wire and then shows to the user.
********************************************************/ 

void WireDiffusion(float length,int sections, double time, int  itime, float k, float rho, float c,float right, float left,float intial,float dx,float dt){	
	WireDimension(length,sections,time,itime,k,rho,c,right,left,intial,dx,dt);
	float s;
	float **u = new float*[itime];
	for(int i = 0; i < itime; i++){
            u[i] = new float[sections]; 
	}

	
	s = (k*dt)/(dx*dx*c*rho); // Calculating the simulation.
	if(s < 0.5){		//If the simulation is less than 0.5.
		for(int i = 0; i < itime; i++){
			for(int j = 0; j < sections; j++){
				if(j == (sections - 1)){
					u[i][j] = right;	//Intializing the right temperature for the wire.
				}else if(j == 0){
					u[i][j] = left;			//Intializing  the left temperature for the wire.
				}
				else{
					u[i][j] = intial;		//Intializing the rest of the temeratures for the wire..
				}
			}	
		}
		for(int i = 1; i < itime; i++){
			for(int j = 1; j < sections-1; j++){	
				u[i][j] = u[i-1][j] +(float) (dt * k * (u[i-1][j+1] - 2 * u[i-1][j] + u[i-1][j-1]))/(float) (c * rho * dx * dx);			
			}	//Implementing the equation an dcalculating the calue of temoerature for rest of index except the right and left.
		}
		for(int i = 0; i < itime; i++){
			for(int j = 0; j < sections; j++){
				cout<<u[i][j]<<"  ";				//Giving some space in between.
			}	
			cout<<endl;
		}
	}	
	else{ 	//if the simulation gets above than 0.5.
		cout<<"Your simulation was unstable!!!"<<endl;	
		cout<<k<<" "<<rho<<" "<<c<<" "<<dx<<" "<<endl;
		exit(0);
	}
	delete_array1(u,itime,sections);
}

/*****************************************
** Function Nanme: plateDimension
** Description: This function gets the dimensions of the plate if the user wants the diffusion of plate and then passes to othe function where diffusion will be calculating.
** Parameters: sections, time, itime, k, rho, c, right, left, intial, dt, dx,dy.
** Input: This function let the user to input all the dimensions for the plate.
** Output: This function passes all the dimensions to other function where the diffusion will be calculating.
*****************************************/ 

void plateDimension(int &sections, double &time,int &itime,float &k,float &rho,float &c,float &bottom_top,float &left_right,float &intial,float &dt,float &dx, float &dy){
	string h="",s="",i="",t="",b="",le="",in="";
	float height,width;
	cout<<"Enter the height and width of the plate: ";
	cin>>h;	//Getting the height, dimension for plate if the user wants the heat diffusion for plate.
	height = verify(h);
	cout<<"Enter the sections across height and width  of plate: ";
	cin>>s;	//Getting the sectins, dimensions for plate if the user wanrs the heat diffusion for plate. 
	sections= verify(s);
	dx = height/sections;	//Calculating dx for the putting in the equation needed to calculate the diffusion.
	dy = height/sections;	// Calculating dy for putting in the equation needed to calculate the diffusion.
	cout<<"For how many time intervals you want the Diffusion: ";
	cin>>i;	//Getting the time interval, dimensions for plate if the user wants the heat diffusion for plate.
	itime= verify(i);
	cout<<"Fow how much time you want to stimulate: ";
	cin>>t;	//getting the time, dimensions for wire if teh user wants the heat diffusion for plate.
	time= verify(t);
	dt = time/itime;	//Calculating dt for the putting in the equation needed to calculate the diffusion.
	cout<<"Enter the bottom/top row  temperature: ";
	cin>>b;	//Getting the bottom and top temperature for plate.
	bottom_top = verify(b);
	cout<<"Enter the left/right column temperature: ";
	cin>>le;	//Getting the right and left temperature for plate.
	left_right = verify(le);
	cout<<"Enter the intial temperature: ";
	cin>>in;		//Getting the intial temperature for plate.
	intial = verify(in);
}
/********************************
** Function Name: delete_array2
** Parameters: u,itime,sections.
** Description: This program is mainly deallocating the array from the heap.
** Input: We pass the array into this function.
** Output: This function deallocates the array from heap.
*********************************/ 

void delete_array2(float ***u,int itime,int sections){
	for(int i =0;i<itime;i++){
		for(int y =0;y<sections;y++){
			delete[] u[i][y];
		}
		delete[] u[i];	
	}
	delete[] u;
}

/****************************************************
** Function Name: plateDiffusion 
** Description: This function get all the dimensions from other function if the user decide to calculate for plate and calculating the diffusion for plate.
** Parameter: sections, time, itime, k, rho, c, right, left, intial, dt, dx, dy.
** Input: The function get all the dimensions from other function.
** Output: This function will calculate the diffusion and then shows to the user.
****************************************************/ 

void plateDiffusion(int sections,double time,int itime, float k,float rho,float c,float bottom_top,float left_right, float intial,float dt,float dx,float dy){

	float s;
	plateDimension(sections,time,itime,k,rho,c,bottom_top,left_right,intial,dt,dx,dy);

	float ***u = new float**[itime];

	for(int i = 0; i < itime; i++){
		u[i] = new float*[sections];
		for(int j = 0; j < sections; j++){
			u[i][j] = new float[sections]; 				
		}	
	}
	 
	s = (k*dt)/(dx*dx*c*rho);		//Calculating simulation for plate.	
	if(s < 0.5){		//If the simulation is less than 0.5.	
		for(int t = 0; t < itime; t++){
			for(int i = 0; i < sections; i++){
				for(int j = 0; j < sections; j++){
					if(j ==  0 || j == sections - 1){
						u[t][i][j] = bottom_top;	//Intializing the bootom and top temperature for the plate.
					}else if(i == 0 || i == sections - 1){
						u[t][i][j] = left_right;	//Intializing the left and right temperature for the plate.
					}
					else{
						u[t][i][j] = intial;	//Intializing the rest of the temperatures for the plate.
					}	
				}
			}	
		}
        	for(int t = 1; t < itime; t++){
			for(int i = 1; i < sections - 1; i++){
				for(int j = 1; j < sections-1; j++){
					u[t][i][j] = u[t-1][i][j] + (((float) (dt * k)/(float)(c * rho))*(((float)(u[t-1][i+1][j] - 2*u[t-1][i][j] + u[t-1][i-1][j])/(float)(dx 						*dx))+	((float)(u[t-1][i][j+1] - 2 * u[t-1][i][j] + u[t-1][i][j-1])/(float)(dy * dy))));
				}		//Calculating the heat diffusion for the plate.
			}
		}
		for(int t = 0; t < itime; t++){
			for(int i = 0; i < sections; i++){
				for(int j = 0; j < sections; j++){
					cout<<u[t][i][j]<<"  ";			//Giving some space in between.	
				}	
				cout<<endl;
			}
			cout<<"\n\n";
		}
	}
	else{		//if the simulation is above 0.5.
		cout<<"Your simulation was unstable!!!"<<endl;	
		cout<< k <<  " "<<rho<<" "<< c <<endl;
		exit(0);
	}
	delete_array2(u,itime,sections);
}
	 
/******************************************
** Function Name: int main
** Description: This function is the main function and include other function and ask some questions and call those functions respectively and calculate the heat diffusion and   print it.
** Paramters: argc,argv.
** Input: Getting input for the questions asking in this funcion from the user and doing what the question wants respectively.
** Output: This function gives the heat transfer to the user.
******************************************/ 

int main(int argc, char ** argv){
	
	//float rho = 0.321, k = 52.4, c = 0.12;
	float length;
	float dx, dt,dy,intial,right,left;
	char *type;
	double time;
	int sections,itime;
	int a,modify,s,play = 1;
	//allows user to modify parameters 
        do{
        float rho=0.321,k=52.4,c=0.12;
		if(argc == 9){		//If the arguments are equal to 9.
			type = processParams(argc, argv, rho, k, c);	
			if(strcmp(type,"plate")==0){	// if the user passed plate in u.
				plateDiffusion(sections,time,itime,k,rho,c,right,left,intial,dt,dx,dy);	
			}
			else if(strcmp(type,"wire")==0){	//If the user passed wire in u.
				WireDiffusion(length,sections,time,itime,k,rho,c,right,left,intial,dx,dt);	
			}
			else{	//If the user passed wrong input in u.
				cout<<"Your object was neither wire nor plate or you must had entered an integer!!!"<<endl;
				exit(0);	
			}
		}
		else if(argc  == 1){	//if the argument is equal to 1.
			
			cout<<"You can also send the constants of simulation as a command line arguments. If you want to send that you can start the program again by entering 1,or you  			 can just continue by entering 0..."<<endl;	// telling the user that they can also passs through command line argument and asking what they want  					to do.
			cin>>a;
			if(a==1){		// if the user want to start over and send the command line arguments.
				exit(0);	
			}
			else if(a==0){
				cout<<"Do you want to modify your constants of simulation (Enter 1 for yes and 0 for no): ";	//Asking if the user wants to modify or not.
				cin>>modify;
				if(modify == 1){	//If the user wants to modify.
					Modify(k,c,rho);
				}	
				cout<<"For which object you want to stimulate, Wire or Plate? (1 for wire and 2 for plate)";	//Asking the user for which object they want the heat  					diffusion.
			        //cin.ignore(numeric_limits<streamsize>::max(), '/n');	
				cin>>s;
				if(s==1){	//If the user wants to see for wire.
					WireDiffusion(length,sections,time,itime,k,rho,c,right,left,intial,dx,dt);		
				}
				else if(s==2){	//If the user wants to see for plate.
					plateDiffusion(sections,time,itime,k,rho,c,right,left,intial,dt,dx,dy);	
				}
			}
		}
		else{
			cout<<"You must not have enough arguments!!!"<<endl;	
		}
	cout<<"Do you want to do again?";
	cin>>play;
	}while(play == 1);
	return (0);
}
