#include <windows.h>
#include "blitz3dsdk.h"
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
int race(std::ifstream & file,int cars,int bots,int laps);
void mathYawToEntity(BBMeshModel src_entity,BBMeshModel dest_entity,float rate );
int mathSign(int x);
int mathSign(int x) {
    if (x < 0)  return -1;
    else        return 1;
}
void mathYawToEntity(BBMeshModel src_entity,BBMeshModel dest_entity,float rate ){
	//Turns 'src_entity' to point at 'dest_entity' at the rotation rate specified by 'rate#'. (we use neg becuase model is fliped at start change this once loaded correctly)
	float target_yaw = -bbDeltaYaw( src_entity, dest_entity );
	
	// If the required correction amount is less than the correction amount to be applied...
	if( abs( target_yaw ) < rate){
		// Point 'src_entity' directly at 'dest_entity' to prevent jittering.
		bbTurnEntity( src_entity, 0.0, target_yaw, 0.0);
	}else{
		// Turn 'src_entity' gradually towards 'dest_entity'.
		bbTurnEntity(src_entity, 0.0, rate * mathSign( target_yaw ), 0.0);
	}
}
class Bullet{
private:
	//xyz physics shit
public:
	BBMeshModel bulletMod;
	int type;
	Bullet();
	Bullet(BBMeshModel mesh,int newType);
	void updateBullet(int player,int type);
};
Bullet::Bullet(){
	bulletMod= bbCreateCube();
	type=0;
}
Bullet::Bullet(BBMeshModel mesh, int newType){
	bulletMod=bbCopyEntity(mesh);
	type=newType;
}
void Bullet::updateBullet(int player,int type){
	switch(type){
		case 0:
			//
			break;
		case 1:
			//
			break;
		case 2:
			//
			break;
		case 3:
			//
			break;
		case 4:
			//
			break;
		case 5:
			//
			break;
		case 6:
			//
			break;
		case 7:
			//bonus.timer=10;
			break;
		case 8:
			//
			break;
		case 9:
			//
			break;
		default:
			//
			break;
	}
}
class BonusBox {// Bonus
public:
	BBMeshModel box;
	void visible(bool vis);
	int bonus,timer;
	BonusBox(BBMeshModel boxMod,BBTexture tex,bool hidden,int type,int x,int y,int z);
	void updateBox();
};
BonusBox::BonusBox(BBMeshModel boxMod,BBTexture tex,bool hidden,int type,int x,int y,int z){
	box=bbCopyEntity(boxMod);
	bbEntityTexture(box,tex);
	//bbEntityType(box,3);
	visible(hidden);
	bonus=type;
	timer=0;
	bbPositionEntity(box,x,y,z);
	bbFreeEntity(boxMod);
}
void BonusBox::visible(bool vis){
	bbHideEntity(box);
	if (vis){
		bbShowEntity(box);
	}
}
void BonusBox::updateBox(){
	//rotate boxes?
	//replace after 10 seconds
}
class Attachment{// Attachment
public:
	int type,timer;
	//bool fireMode;
	BBMeshModel attachMod;
	Attachment();
	Attachment(BBMeshModel type);
	void visible(bool vis);
	bool update();
	void updateFire();
	/*Types of attachments
	0=Graphics/shrum.3ds
	1=Graphics/boost.3ds
	2=Graphics/flame.3ds
	3=Graphics/shield.3ds
	4=Graphics/mac-gun.3ds
	5=Graphics/can-gun.3ds
	6=Graphics/hom-gun.3ds
	7=Graphics/mag-mine.3ds
	8=Graphics/oil-mine.3ds
	9=Graphics/sen-mine.3ds
	*/
};
Attachment::Attachment(){
	//
}
Attachment::Attachment(BBMeshModel type){
	attachMod=bbCopyEntity(type);
	bbScaleEntity(attachMod,2,2,2);
	bbHideEntity(attachMod);
	timer=0;
}
void Attachment::visible(bool vis){
	bbHideEntity(attachMod);
	//bbEntityAlpha(attachMod,0);
	if (vis){
		bbShowEntity(attachMod);
		//timer=clock()+10000;
	}
}
bool Attachment::update(){
	//update each type of atachment
	switch(type){
		/*case 0:
			//
			break;
		case 1:
			//
			break;
		case 2:
			//
			break;
		case 3:
			//
			break;
		case 4:
			//
			break;
		case 5:
			//
			break;
		case 6:
			//
			break;*/
		case 7:
			//emit beeps?
			//blinking light?
			//if fire? make bullet on ground of position
			return false;
			break;
		/*case 8:
			//
			break;
		case 9:
			//
			break;*/
		default:
			//check the timers
			if(timer<clock()){
				visible(false);
				timer=0;
				return false;
			}
			return true;
	}

	
	
}
void Attachment::updateFire(){
	//
}
class Car {// Car
private:
	float gravity; 
public:
	bool hasBonus,isSpun,finished;
	BBMeshModel body;
	Attachment bonus;
	BBCamera camera;
	BBLight light;
	int time,place,player,attachments[4],amtBullets;
	int ** gateTime;
	int currentGate,currentLap;
	float xPos,yPos,zPos,xVel,yVel,zVel,xAcc,yAcc,zAcc;
	//Car();
	Car (BBMeshModel bodyMod,int p,int laps,int gates);
    void updateDrones(BBMeshModel gate[]);
	void updatePlayer();
	void followCamera();
	void setGateTime();
	void spinOut();
	void loadAttachment();
	void updateAttachments();
};
Car::Car (BBMeshModel bodyMod,int p,int laps,int gates) {
	//inital settings
	gravity=-0.01,xVel=0,yVel=-.5,zVel=0,xAcc=0,yAcc=0,zAcc=0; 
	body=bbCopyEntity(bodyMod);
	//attachments
	for(int index=0;index<4;index++){
		attachments[index]=-1;
	}
	bonus = Attachment(bbCreateCube());
	bonus.visible(false);
	hasBonus=false;
	amtBullets=0;
	//
	finished=false;
	//Get world Position
	xPos=bbEntityX(body);
	yPos=bbEntityY(body);
	zPos=bbEntityZ(body);
	//Scale and Center on  pivot
	//bbRotateEntity(body,0,180,0);
	bbFitMesh(body,xPos,yPos,zPos,3,3,3);
	float w=bbMeshWidth(body),h=bbMeshHeight(body),d=bbMeshDepth(body);
	bbFitMesh(body, -w*.5, -h*.5, -d*.5, w,h,d);
	//collisions types
	bbEntityType(body,1);
	bbEntityRadius(body,1.5);
	//which player
	player=p;
	//camera&light(aka god)
	camera=bbCreateCamera();
	bbCameraClsColor( camera,0,0,255);// blue skyline haha
	light=bbCreateLight(1,camera);
	//countdown
	time=-8;
	//intialize timers
	gateTime= new int*[gates];
	for(int index=0;index<gates;index++){
		gateTime[index]= new int[laps];
		for(int index2=0;index2<laps;index2++){
			gateTime[index][index2]=0;
		}
	}
	currentGate=0;
	currentLap=0;
	place=player+1;
}
void Car::loadAttachment(){
	//load next attachment
	bonus.type=attachments[0];
	//scale accordingly
	bbEntityParent(bonus.attachMod,body);// attach to car as child
	bonus.timer=clock()+10000;
	switch(bonus.type){
		case 0:
			//
			break;
		case 1:
			//
			break;
		case 2:
			//
			break;
		case 3:
			//
			break;
		case 4:
			//
			break;
		case 5:
			//
			break;
		case 6:
			//
			break;
		case 7:
			bbScaleEntity(bonus.attachMod,.5,.5,.5);
			bbPositionEntity(bonus.attachMod,xPos,yPos,zPos-1);
			//bonus.timer=10;
			break;
		case 8:
			//
			break;
		case 9:
			//
			break;
		default:
			//
			break;
	}
	
	hasBonus=true;//tell player he has an attachment
	bonus.visible(true);//Show the attachment
	//cycle through list of attachments
	for(int attch=0;attch<3;attch++){
		attachments[attch]=attachments[attch+1];
	}
	attachments[3]=-1; // clear for new attachment at the end of array
}
void Car::updateAttachments(){
	//update the attachment
	hasBonus=bonus.update();
	// if fire amtBullets++;
	if((bbKeyDown(58)&&player==0)||(bbJoyDown(4)&&player>=1)){//fire mode?
		// if type needs bullets amtBullets++;	
		//hasBonus=false;
	}
}
void Car::updateDrones(BBMeshModel gate[]){
	//your coordantes
	xPos=bbEntityX(body);
	yPos=bbEntityY(body);
	zPos=bbEntityZ(body);
	//gates coordnates
	//int x,z;
	//x=bbEntityX(gate);
	//z=bbEntityZ(gate);

	if((time>=0)&&(!finished)){
		//int gw=bbGraphicsWidth();
		//acceleration?
		if(true){//acceleration? rear thrusts
			//use actual physics maybe?
			bbTFormVector(0,0,-0.02,body,0);
			xAcc=bbTFormedX();
			yAcc=bbTFormedY();
			zAcc=bbTFormedZ();
			if((xVel>2)||(xVel<-2)){//cant go to fast on x axis
				xVel+=-xAcc;
			}
			if((zVel>2)||(zVel<-2)){//cant go to fast on z axis
				zVel+=-zAcc;
			}
		}
	
		//turning?
		//bbPointEntity(body,gate[currentGate]);
		float dist = bbEntityDistance(body,gate[currentGate]);
		/*bool allowTurn;
		if(allowTurn){
			if (dist < 10){
				if( abs( bbDeltaYaw( body, gate[currentGate] ) ) > 90){
					disable_allow_turn_when_pointing_up = true;
				}
			}
		}else{
			if (dist > 20){
				allowTurn = true;
			}
		}
		if (disable_allow_turn_when_pointing_up){
			if( Abs( EntityYaw( cone ) ) < 89.0 ){// Note: 89 degrees is used so that the missile will turn upwards.
				allow_turn = false;
				disable_allow_turn_when_pointing_up = false;
			}
		}*/
		if(dist>10){
			mathYawToEntity(body, gate[currentGate],1);
		}
		//bbDeltaYaw(body,gate[currentGate]);
		//bbMoveEntity(body, 0.0, 0.0, 0.5);
	}
		yVel=yVel+gravity;
		//apply acceleration to velocity
		xVel=xVel+xAcc;
		yVel=yVel+yAcc;
		zVel=zVel+zAcc;
		//move the body		
		bbTranslateEntity (body,xVel,yVel,zVel);
		//reposition entitys in camera
		bbUpdateWorld();
		if(bbEntityCollided(body,2)){//check if car is on ground
			xVel=xVel*0.98;//apply friction
			yVel=yVel*0.98;
			zVel=zVel*0.98;
			//accelerate vertical thrusts
			//if((bbKeyDown(57)&&player==0)||(bbJoyDown(1)&&player>=1)){
			//	bbTFormVector( 0,.3,0,body,0);	
			//	xVel+=bbTFormedX();
			//	yVel+=bbTFormedY();
			//	zVel+=bbTFormedZ();
			//}
		}else{
			yVel*=.95;// extra gravity? aid in free fall
		}
		//reset acclerations
		xAcc=0;
		yAcc=0;
		zAcc=0;
		//attachments?================================================================
/*		if(hasBonus){// if car has bonus
			if(!(bonus->update())){//if not updateing?
				hasBonus=false;
				bonus->visible(false);
			}
			if((bbKeyDown(58)&&player==2)||(bbJoyDown(4)&&player>=1)){//fire mode?
				
				hasBonus=false;
				bonus->visible(false);
			}
		}
		*/
	//bbPositionEntity(body,newX,newY,newZ);
	//followCamera();
	
}
void Car::updatePlayer(){
	//get positions
		xPos=bbEntityX(body);
		yPos=bbEntityY(body);
		zPos=bbEntityZ(body);
	//input
	//gas
	//Start up Count down (allow input only during gameplay)
	if((time>=0)&&(!finished)){
		if((bbKeyDown(200)&&player==0)||(bbJoyDown(2)&&player>=1)){//acceleration? rear thrusts
			bbTFormVector(0,0,-0.02,body,0);
			xAcc=bbTFormedX();
			yAcc=bbTFormedY();
			zAcc=bbTFormedZ();
			if((xVel>2)||(xVel<-2)){//cant go to fast on x axis
				xVel+=-xAcc;
			}
			if((zVel>2)||(zVel<-2)){//cant go to fast on z axis
				zVel+=-zAcc;
			}
		}
		//stop	
		if((bbKeyDown(208)&&player==0)||(bbJoyDown(3)&&player>=1)){
			xVel=xVel*0.99;
			yVel=yVel*0.99;
			zVel=zVel*0.99;
		}
		//if on ground
		//turns
		if((bbKeyDown(203)&&player==0)||((bbJoyXDir()<0)&&player>=1)){
			bbTurnEntity(body,0,2,0);
		}
		if((bbKeyDown(205)&&player==0)||((bbJoyXDir()>0)&&player>=1)){
			bbTurnEntity(body,0,-2,0);
		}
	}

		yVel=yVel+gravity;
		//apply acceleration to velocity
		xVel=xVel+xAcc;
		yVel=yVel+yAcc;
		zVel=zVel+zAcc;
		//move the body		
		bbTranslateEntity (body,xVel,yVel,zVel);
		//reposition entitys in camera
		bbUpdateWorld();
		if(bbEntityCollided(body,2)){//check if car is on ground
			xVel=xVel*0.98;
			yVel=yVel*0.98;
			zVel=zVel*0.98;
			//accelerate vertical thrusts
			if((bbKeyDown(57)&&player==0)||(bbJoyDown(1)&&player>=1)){
				bbTFormVector( 0,.3,0,body,0);	
				xVel+=bbTFormedX();
				yVel+=bbTFormedY();
				zVel+=bbTFormedZ();
			}
		}else{
			yVel*=.97;// extra gravity?
		}
		//reset acclerations
		xAcc=0;
		yAcc=0;
		zAcc=0;
		
		//camer updat
		followCamera();
		//spinWheels(3);
}
void Car::setGateTime(){
	gateTime[currentGate][currentLap]=time;// record keeping for each gate
}
void Car::followCamera(){
	bbTFormPoint(0,2,10,body,0);
	float dx=(bbTFormedX()-bbEntityX(camera))*.1;
	float dy=(bbTFormedY()-bbEntityY(camera))*.1;
	float dz=(bbTFormedZ()-bbEntityZ(camera))*.1;
	bbTranslateEntity(camera,dx,dy,dz);
	bbPointEntity(camera,body);
}
class Level {// Level
public:
	int cars,bots,laps,numGates;
	Bullet * bullets[200];
	BonusBox * boxs[12];
	BBMeshModel gates[12];
	BBMeshModel attachments[10];
	BBTerrain map;
	Car *players[4];
	BBTexture terTex,skyTex;
	BBSprite Trees[100];
	//BBImage arrow;
	Level(BBMeshModel ter,BBTexture terTex,BBMeshModel sky,BBTexture skyTex,BBMeshModel carMesh,int laps, int cars,int bots, int xPos, int zPos);
	void updateAttachments(int amtPlayers);
	void updateBullets(int amtPlayers);
	void updateBoxes();
	void loadGates(int gatePos[][4], BBMeshModel temp);
	void updateGates();
	void updateArrow(int index,int x, int y,int gw,int gh);
	void carTracks(int index);
	void loadTrees(BBSprite tree);
	void updateText();
	void winnerScene(int first);
	int findWinner();
	bool gameOver();
	
};
Level::Level(BBMeshModel ter,BBTexture terTex,BBMeshModel sky,BBTexture skyTex,BBMeshModel carMesh,int lapAmount, int carAmount,int botAmount, int xPos, int zPos){
	cars=carAmount;
	laps=lapAmount;
	bots=botAmount;
	numGates=12;
	//terrain-----------------------------------------
	bbEntityType(ter,2);
	map=ter;
	bbTerrainDetail(map,4000,0);
	bbScaleTexture(terTex,1024,1024);
	bbEntityTexture(map,terTex);
	bbScaleEntity(map,1,10,1);
	bbTerrainShading(map,true);
	//skybox--------------------------------------------
	bbScaleEntity(sky,512,-20,512);
	bbPositionEntity(sky,512,10,512);
	bbEntityTexture(sky,skyTex);
	bbEntityAlpha(sky,.5);
	bbEntityType(sky,2);
	bbEntityOrder(sky,1);
	
	//set up cars-------------------------------------------
	for(int index=0;index<(cars+bots);index++){//set up human players
		players[index] = new Car(carMesh,index,laps,numGates);
		bbPositionEntity(players[index]->body,xPos+(index*4),30,zPos+20);
	}
	bbFreeEntity(carMesh);
	//set up screens depending on player------------------------------
	int gw=bbGraphicsWidth();
	int gh=bbGraphicsHeight();
	if (cars==1){
		bbCameraViewport(players[0]->camera,0,0,gw,gh);
	}else if(cars==2){
		bbCameraViewport(players[0]->camera,0,0,gw,gh/2);
		bbCameraViewport(players[1]->camera,0,gh/2,gw,gh/2);
	}else if(cars==3){
		bbCameraViewport(players[0]->camera,0,0,gw,gh/2);
		bbCameraViewport(players[1]->camera,0,gh/2,gw/2,gh/2);
		bbCameraViewport(players[2]->camera,gw/2,gh/2,gw/2,gh/2);
	}else if(cars==4){
		bbCameraViewport(players[0]->camera,0,0,gw/2,gh/2);
		bbCameraViewport(players[1]->camera,gw/2,0,gw/2,gh/2);
		bbCameraViewport(players[2]->camera,0,gh/2,gw/2,gh/2);
		bbCameraViewport(players[3]->camera,gw/2,gh/2,gw/2,gh/2);
	}
	//Cheat to see enemy camera
	for(int index=0;index<bots;index++){
		bbCameraViewport(players[index+cars]->camera,0,0,0,0);
	}
	//bonusboxs-----------------------------------------------
	float x,y=5, z;
	for(int index=0;index<12;index++){
		do{
			x=(rand()%1024);
			z=(rand()%1024);
		}while(bbTerrainY(map,x,y,z)>3); //check to see if its on the road
		boxs[index]=new BonusBox(bbCreateCube(),bbLoadTexture("Graphics/crate.jpg"),true,(rand()%10),x,y,z);// positinon box
		//bonus box ten differ//types defined below
	}
	//car attachments/bonus models-------------------------------------------------
	for(int index=0;index<10;index++){
		attachments[index]=bbCreateSphere();
		bbHideEntity(attachments[index]);
	}
	//arrow=bbLoadImage("redcursor.jpg");
}
void Level::updateAttachments(int amtPlayers){
	//attachments?================================================================
	for(int index=0;index<amtPlayers;index++){
		if(players[index]->hasBonus){// if car has bonus
			players[index]->updateAttachments();//start updating the attachments
		}else {
			if(players[index]->attachments[0]!=-1){
				if((((bbKeyDown(54)||bbKeyDown(42)))&&index==0)||(bbJoyDown(4)&&index>=1)){//load attachment?
					players[index]->bonus.attachMod=bbCopyEntity(attachments[players[index]->attachments[0]]);//out of levels attachments, decide which one to copy
					players[index]->loadAttachment();
				}
			}
		}
	}
}
void Level::updateBullets(int amtPlayers){
	int totalBullets=0;
	for(int index=0;index<amtPlayers;index++){		
		for(int index=0;index<players[index]->amtBullets;index++){
			totalBullets++;
			bullets[totalBullets]->updateBullet(index,players[index]->bonus.type);
		}
	}
}
void Level::updateBoxes(){
	for(int index=0;index<12;index++){// go though boxes
		if (boxs[index]->timer==0){ //if its avalible
		bbTurnEntity(boxs[index]->box,0,1,0);
		for(int player=0;player<(cars+bots);player++){// check which player
			if(bbEntityDistance(players[player]->body,boxs[index]->box)<3){ //which box player hit and 
				if((players[player]->attachments[3])==-1){// check if there is room for attachment
					boxs[index]->visible(false);// dissaperar box
					//bbResetEntity(boxs[index]->box);
					boxs[index]->timer=(int)clock()+10000;//set timer to reapear
					//add next value type to array of attachemts
					int attch=0;
					while((players[player]->attachments[attch])!=-1){
						attch++;
					}
					players[player]->attachments[attch]=boxs[index]->bonus;
					
				}
			}
		}
		}
		if((boxs[index]->timer<(int)clock())&&(boxs[index]->timer>0)){
			boxs[index]->visible(true);
			boxs[index]->timer=0;
			//Re-randomize ?
			int x,z;
			do{
				x=(rand()%1000);
				z=(rand()%1000);
			}while(bbTerrainY(map,x,5,z)>3); 
			bbPositionEntity(boxs[index]->box,x,5,z);
			boxs[index]->bonus=(rand()%10);
			//end random
		}
	}
}
void Level::loadGates(int gatePos[][4],BBMeshModel temp){
	float x,z;
	for (int index=0; index<numGates; index++){
		gates[index]=bbCopyEntity(temp);
		bbScaleEntity(gates[index],10,10,1);
//		bbFitMesh(gates[index],bbEntityX(gates[index]),bbEntityY(gates[index]),bbEntityZ(gates[index]),10,10,1);
		bbEntityColor(gates[index],255,0,0);
		bbPositionEntity(temp,gatePos[index][2],5,gatePos[index][3]);
		x=(gatePos[index][0]+gatePos[index][2])/2;
		z=(gatePos[index][1]+gatePos[index][3])/2;
//		bbPositionEntity(gates[index],gatePos[index][0],5,gatePos[index][1]);
		bbPointEntity(gates[index],temp);
		bbPositionEntity(gates[index],x,5,z);
//		bbPositionEntity(gates[index],(gatePos[index][0])+((gatePos[index][0])-(gatePos[index][2])),5,(gatePos[index][1])+((gatePos[index][1])-(gatePos[index][3])));
	}
	bbFreeEntity(temp);
}
void Level::updateGates(){
	for (int index=0; index<(cars+bots); index++){
		if(bbMeshesIntersect(players[index]->body,gates[players[index]->currentGate])){
			players[index]->setGateTime();
			//update to next gate
			if(players[index]->currentGate<(numGates-1)){
				players[index]->currentGate++;
			}else{
				players[index]->currentGate=0;
				if(players[index]->currentLap<(laps-1)){
					players[index]->currentLap++;
				}else{
					//frezze current player
					players[index]->finished=true;
					//let others finish up game
				}
			}
			//players[index]->gateTime[currentGate][currentLap]
			
			
		}
		//bbPointEntity(gate[index],players[0]->body);
	}
	
}
void Level::updateArrow(int index,int xPos, int yPos,int gw,int gh){
	bbTFormPoint(0,0,0,gates[players[index]->currentGate], players[index]->camera);
	int x=xPos+(gw/2)+bbTFormedX();
	if(x>gw-5){
		x=gw-5;
	}else if(x<xPos+5){
		x=xPos+5;
	}
	//if(bbTFormedY()<0
	bbRect((xPos+x)-2,yPos,4,gh/10);
}
void Level::carTracks(int index){
	//
	//bbSetBuffer(bbTextureBuffer(terTex));
	//bbColor(255,0,0);
	//bbPlot(players[index]->xPos,players[index]->zPos);
	//bbSetBuffer(bbBackBuffer());
}/**/
void Level::loadTrees(BBSprite tree){
	float x,y,z;
	bbScaleSprite(tree,10,10);
	for(int index=0;index<50;index++){
		do{
			x=(rand()%1024);
			z=(rand()%1024);
			y=bbTerrainY(map,x,5,z);
		}while(y<5); //check to see if its on the road
		Trees[index]= bbCopyEntity(tree);
		bbPositionEntity(Trees[index],x,y,z);
	}
}
void Level::updateText(){
	char text[10];
	bbColor(255,0,0);
	int gw=bbGraphicsWidth();
	int gh=bbGraphicsHeight();
	int time=abs(players[0]->time);
	//update HUD per players screen
	if (cars==1){
		updateArrow(0,0,0,gw,gh);
		if(players[0]->time<0){
			bbText(gw/2,gh/2,_itoa(time,text,10),1,1);
		}
		for(int index=0;index<numGates;index++){
			bbText(gw/20,(gh/20)+(index*10),_itoa(players[0]->gateTime[index][players[0]->currentLap],text,10));
		}
		for(int index=0;index<4;index++){
			bbText(gw-(gw/20),(gh/20)+(index*10),_itoa(players[0]->attachments[index],text,10));
		}
	}else if(cars==2){
		updateArrow(0,0,0,gw,gh/2);
		if(players[0]->time<0){
			bbText(gw/2,gh/4,_itoa(time,text,10),1,1);
		}
		updateArrow(1,0,gh/2,gw,gh/2);
		if(players[1]->time<0){
			bbText(gw/2,(gh/4)*3,_itoa(time,text,10),1,1);
		}
		for(int index=0;index<numGates;index++){
			bbText(gw/20,(gh/20)+(index*10),_itoa(players[0]->gateTime[index][players[0]->currentLap],text,10));
			bbText(gw/20,((gh/2)+(gh/20))+(index*10),_itoa(players[1]->gateTime[index][players[1]->currentLap],text,10));
		}
	}else if(cars==3){
		updateArrow(0,0,0,gw,gh/2);
		if(players[0]->time<0){
			bbText(gw/2,gh/4,_itoa(time,text,10),1,1);
		}
		updateArrow(1,0,gh/2,gw/2,gh/2);
		if(players[1]->time<0){
			bbText(gw/4,(gh/4)*3,_itoa(time,text,10),1,1);
		}
		updateArrow(2,gw/2,gh/2,gw/4,gh/2);
		if(players[2]->time<0){
			bbText((gw/4)*3,(gh/4)*3,_itoa(time,text,10),1,1);
		}
		for(int index=0;index<numGates;index++){
			bbText(gw/20,(gh/20)+(index*10),_itoa(players[0]->gateTime[index][players[0]->currentLap],text,10));
			bbText(gw/20,((gh/2)+(gh/20))+(index*10),_itoa(players[1]->gateTime[index][players[1]->currentLap],text,10));
			bbText((gw/2)+(gw/20),((gh/2)+(gh/20))+(index*10),_itoa(players[2]->gateTime[index][players[2]->currentLap],text,10));
		}
	}else if(cars==4){
		updateArrow(0,0,0,gw/2,gh/2);
		if(players[0]->time<0){
			bbText(gw/4,gh/4,_itoa(time,text,10),1,1);
		}
		updateArrow(1,gw/2,0,gw/4,gh/2);
		if(players[1]->time<0){
			bbText(gw/4*3,gh/4,_itoa(time,text,10),1,1);
		}
		updateArrow(2,0,gh/2,gw/2,gh/2);
		if(players[2]->time<0){
			bbText(gw/4,(gh/4)*3,_itoa(time,text,10),1,1);
		}
		updateArrow(3,gw/2,gh/2,gw/4,gh/2);
		if(players[3]->time<0){
			bbText((gw/4)*3,(gh/4)*3,_itoa(time,text,10),1,1);
		}
		for(int index=0;index<numGates;index++){
			bbText(gw/20,(gh/20)+(index*10),_itoa(players[0]->gateTime[index][players[0]->currentLap],text,10));
			bbText((gw/2)+(gw/20),(gh/20)+(index*10),_itoa(players[1]->gateTime[index][players[1]->currentLap],text,10));
			bbText(gw/20,((gh/2)+(gh/20))+(index*10),_itoa(players[2]->gateTime[index][players[2]->currentLap],text,10));
			bbText((gw/2)+(gw/20),((gh/2)+(gh/20))+(index*10),_itoa(players[3]->gateTime[index][players[3]->currentLap],text,10));
		}
	}/*
	if(level.players[0]->time<0){
		bbText(gw,(gh/2),_itoa(abs(level.players[0]->time),text,10),1,1);
	}
	bbText(10,20,_itoa(level.players[0]->currentGate,text,10));
	bbText(10,30,_itoa(level.players[0]->currentLap+1,text,10));
	//bbText(10,30,_itoa((int)bbEntityY(level.players[0]->body),text,10));
	for(int index=0;index<10;index++){
		bbText(10,40+(index*10),_itoa(level.players[0]->gateTime[index][level.players[0]->currentLap],text,10));
	}
	if(level.players[1]->time<0){
		bbText(gw,(gh/2)*3,_itoa(abs(level.players[1]->time),text,10),1,1);
	}/*
	bbText(10,(gh+20),_itoa(level.players[1]->currentGate,text,10));
	bbText(10,(gh+30),_itoa(level.players[1]->currentLap+1,text,10));
	//bbText(10,30,_itoa((int)bbEntityY(level.players[0]->body),text,10));
	for(int index=0;index<10;index++){
		bbText(10,(gh+40)+(index*10),_itoa(level.players[1]->gateTime[index][level.players[1]->currentLap],text,10));
	}*/
}
void Level::winnerScene(int first){
	int gw=bbGraphicsWidth();
	int gh=bbGraphicsHeight();
	bbCls();
	//zoom effect
	bbCameraViewport(players[first]->camera,0,0,gw,gh);
	bbText(gw/2,gh/2,"Winner!");//replace with fancy winner image
	bbFlip();
	//sleep();
	bbWaitKey();
}
int Level::findWinner(){
	for(int index=0;index<(cars+bots);index++){
		if (players[index]->place==1){
			return index;
		}
	}
	return 0;
}
bool Level::gameOver(){
	int temp=0;
	for(int index=0;index<(cars+bots);index++){
		if(players[index]->finished){
			temp++;
		}
	}
	if(temp==(cars+bots)){
		return true;
	}
	return false;
}

//Global start race(loading screen here too?)
int race(std::ifstream & file,int cars,int bots,int laps){
	//LoadLevelFrom Configfile
	string line[25];
	//different bassed upon levels?
	int gatePos[12][4];
	int indexPos,endPos;
	for(int index=0;index<36;index++){
		//parse file for objs paths
		if(index<24){
			getline (file,line[index]);
		//next load Gate Positions
		}else {
			getline (file,line[24]);
			if(index>23){
				endPos=0;
				indexPos=0;
				for(int index2=0;index2<4;index2++){//break down each line into numbers
					endPos=line[24].find_first_of(",",indexPos);
					gatePos[index-24][index2]=(int)atoi(line[24].substr(indexPos,(endPos-indexPos)).c_str());
					indexPos=endPos+1;
				}
			}
		}
	}
	file.close();//close file
	//put level objects where they go-------------------------------------------------
	Level level(bbLoadTerrain(line[0].c_str()),bbLoadTexture(line[1].c_str()),bbCreateCube(),bbLoadTexture(line[3].c_str()),bbLoadMesh(line[4].c_str()),laps,cars,bots,gatePos[0][0],gatePos[0][1]);
	//level.loadGates(gatePos,bbLoadMesh(line[4].c_str()));
	//Level level(bbLoadTerrain("Graphics/map.jpg"),bbLoadTexture("Graphics/mapcolor.jpg"),bbCreateCube(),bbLoadTexture("Graphics/sky.jpg"),bbLoadMesh("Graphics/car.3ds"),laps,cars,100,100);
	level.loadGates(gatePos,bbCreateCube());//bbLoadMesh("Graphics/car.3ds"));
	//Scenery--------------------------------------------
	level.loadTrees(bbLoadSprite(line[21].c_str()));
	//collisions--------------------------------------
	//Car=1;
	//Ground=2
	//Boxes=3;
	//Scenery=4;
	bbCollisions(1,2,2,2);
	bbCollisions(1,3,2,2);
	//start gameplay-------------------------------------
	char text[10];
	int setfps=0,getfps=0,settime=0;
	//race
	while (!bbKeyHit(1)){
		//start 3D updates
		//update you
		for(int index=0;index<cars;index++){
			level.players[index]->updatePlayer();
			//level.carTracks(index);
		}
		//updatedrones
		for(int index=0;index<bots;index++){
			level.players[cars+index]->updateDrones(level.gates);
			//level.carTracks(cars+index);
		}
		//updateworld
		level.updateAttachments(cars+bots);
		//level.updateBullets(cars+bots);
		level.updateBoxes();
		level.updateGates();
		//end game?
		if(level.gameOver()){
			level.winnerScene(level.findWinner());
			//render winning screen
			//go back to menu screen
			return 0;
		}
		
		//3D screen Render
		bbRenderWorld();
		//text ( 2D start updates
		if ((clock()-settime)>1000){
			getfps=setfps; 
			setfps=0; 
			settime=clock();
			for(int index=0;index<(cars+bots);index++){
				level.players[index]->time++;
			}
		}else{
			setfps=setfps+1;
		}
		level.updateText();
		//2D Render
		//debug stuff
		bbText(30,10,_itoa(getfps,text,10));
		bbText(30,20,_itoa(level.players[0]->bonus.timer,text,10));
		bbFlip();
	}

	bbClearWorld(1,1,1);
	return 0;
};

class Menu {//menu
public:
	ifstream myfile;
	int level,cars,bots,laps,volume;
	Menu();
	BBImage backGround,buttonStart,buttonOptions,buttonCredits,buttonQuit,cursor;
	int MainMenu();
	int Options();
	int Credits();
	int StartGame();
	
};
Menu::Menu(){
	//bbAutoMidHandle(true);
	backGround=bbLoadImage("Graphics/Title.jpg");
	bbResizeImage(backGround,bbGraphicsWidth(),bbGraphicsHeight());
	buttonStart=bbLoadImage("Graphics/buttonStartgame.jpg");
	buttonOptions=bbLoadImage("Graphics/buttonoptions.jpg");
	buttonCredits=bbLoadImage("Graphics/buttoncredits.jpg");
	buttonQuit=bbLoadImage("Graphics/buttonquit.jpg");
	cursor=bbLoadImage("Graphics/RedCursor.bmp");
}
int Menu::MainMenu(){
	bbHidePointer();
    int gw=(bbGraphicsWidth()/2)-150;
	int gh=bbGraphicsHeight()/6;
	
    int result=0,mx,my;
	while(result==0){
        bbCls();
		mx=bbMouseX();
		my=bbMouseY();
		bbDrawImage(backGround,0,0,0);
		bbDrawImage(buttonStart,gw,gh*2,0);
		bbDrawImage(buttonOptions,gw,gh*3,0);
		bbDrawImage(buttonCredits,gw,gh*4,0);
		bbDrawImage(buttonQuit,gw,gh*5,0);
		bbDrawImage(cursor,mx,my,0);
		if (bbMouseHit(1)){
			if (bbImagesOverlap(buttonStart,gw,gh*2,cursor,mx,my)){ result = 1;}
			if (bbImagesOverlap(buttonOptions,gw,gh*3,cursor,mx,my)){ result = 2;}
			if (bbImagesOverlap(buttonCredits,gw,gh*4,cursor,mx,my)){ result = 3;}
			if (bbImagesOverlap(buttonQuit,gw,gh*5,cursor,mx,my)){ result = 4;}
		}
		bbFlip();
	}
	//Values of gameplay or where they will be set
	cars=1;
	bots=2;
	laps=1;
    return result;
}
int Menu::Options(){
    bbCls();
    bbText(400,300,"Options Screen! Any key to return to main menu",1,1);
//	bbText(400,200,"Level"& level,1,1);
//	bbText(400,210,"Players"& players,1,1);
//	bbText(400,220,"Bots"&bots,1,1);
//	bbText(400,240,"Laps"&laps,1,1);
//	bbText(400,250,"Volume"&volume,1,1);
    //allow for adjusting settings
	bbFlip();
	
    bbWaitKey();
    return 0;
}
int Menu::Credits(){
	// crazy graphics, blah blah blah
    bbCls();
    bbText( 400,300,"Credits!!",1,1);
    bbText( 400,330,"Game Created By Kyle Johnson",1,1);
    bbText( 400,400,"Any key to return",1,1);
	bbFlip();
    bbWaitKey();
    return 0;
}
int Menu::StartGame(){
    bbCls();
	//select level
	myfile.open ("Levels.txt");
	//	
	//Start Load
	if (myfile.is_open())
	{
		//return (Test(myfile)+10);
		return (race(myfile,cars,bots,laps));
	}
	myfile.close();
	
    return 0;
}
extern int WINAPI WinMain(HINSTANCE hThisInst,HINSTANCE hPrevInst,LPSTR lpszArgs,int nWinMode){
	bbBeginBlitz3D();
	//bbGraphics3D(1366,768,32,1);//start graphics
	bbGraphics3D(800,600,32,3);//test graphics
	Menu title;
	int result=0;
	while(result==0){
		//decide which screen to display
		result=title.MainMenu();
		bbFlushMouse();
		bbFlushKeys();
		//bbFlush
		if(result==2){ 
			result=title.Options();
		}
		if(result==3){
			result=title.Credits();
		}
		if(result==1){
			result=title.StartGame();
		}
	}
	bbEndBlitz3D();
	return 0;
}