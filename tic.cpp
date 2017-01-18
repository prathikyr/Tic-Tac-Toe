#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

int marked[3][3];
GLfloat ver[3][3][2] = {{{-0.4, 0.4}, {0.0, 0.4}, {0.4, 0.4}}, {{-0.4, 0.0}, {0.0, 0.0}, {0.4, 0.0}}, {{-0.4, -0.4}, {0.0, -0.4}, {0.4, -0.4}}};
char vic1[] = "You Win";
char vic2[] = "You Lost";
char vic3[] = "Draw";
char moveC[] = "O";
char moveP[] = "X";
<<<<<<< HEAD
//char lb[] = "LeaderBoard";
=======
char ng[] = "New Game";
>>>>>>> f9318312c36dc03731085aebd36b778f665caa68
bool playerMove = true;
bool matchIsGoingOn = true;

void printString(char s[], GLfloat x, GLfloat y, GLfloat z){
	glRasterPos3f(x, y, z);
	for(int i=0; s[i]; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
	glFlush();
}

void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2){
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
	glEnd();
}

void drawTicTacToe(){
	drawLine(-0.2, 0.6, -0.2, -0.6);
	drawLine(0.2, 0.6, 0.2, -0.6);
	drawLine(-0.6, 0.2, 0.6, 0.2);
	drawLine(-0.6, -0.2, 0.6, -0.2);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	
	drawTicTacToe();
	/*glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex2f(0.5, 0.9);
		glVertex2f(0.9, 0.9);
		glVertex2f(0.9, 0.8);
		glVertex2f(0.5, 0.8);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
<<<<<<< HEAD
	printString(lb, 0.52, 0.83, 0.0);*/
=======
	printString(ng, 0.52, 0.83, 0.0);
>>>>>>> f9318312c36dc03731085aebd36b778f665caa68
	glFlush();
}

bool insideBox(GLfloat a, GLfloat b, GLfloat x, GLfloat y){
	if((x>=a && y<=b) && (x<=a+0.4 && y>=b-0.4))
		return true;
	return false;	
}

bool victory(int p){
	//row victory
	for(int i=0; i<3; i++){
		bool flag = true;
		for(int j=0; j<3; j++){
			if(marked[i][j] != p){
				flag = false;
				break;
			}
		}
		if(flag == true){
			matchIsGoingOn = false;
			return true;
		}
	}

	//Column vitory
	for(int i=0; i<3; i++){
		bool flag = true;
		for(int j=0; j<3; j++){
			if(marked[j][i] != p){
				flag = false;
				break;
			}
		}
		if(flag == true){
			matchIsGoingOn = false;
			return true;
		}
	}
	
	//Diagonal1 victory
	bool flag = true;
	for(int i=0; i<3; i++)
		if(marked[i][i] != p)
			flag = false;
	if(flag){
		matchIsGoingOn = false;
		return true;
	}
	
	//Diagonal2 victory	
	flag = true;
	for(int i=0; i<3; i++)
		if(marked[i][2-i] != p)
			flag = false;
	if(flag){
		matchIsGoingOn = false;
		return true;
	}
		
	return false;
}

bool moveInRow(int r){
	int i;
	for(i=0; i<3; i++)
		if(marked[r][i]==0){
			marked[r][i]=2;
			printString(moveC, ver[r][i][0], ver[r][i][1], 0.0);
			return true;
		}
	return false;
}

bool moveInCol(int c){
	int i;
	for(i=0; i<3; i++)
		if(marked[i][c]==0){
			marked[i][c]=2;
			printString(moveC, ver[i][c][0], ver[i][c][1], 0.0);
			return true;
		}
	return false;
}

bool movePri(){
	int i;
	for(i=0; i<3; i++)
		if(marked[i][i]==0){
			marked[i][i]=2;
			printString(moveC, ver[i][i][0], ver[i][i][1], 0.0);
			return true;
		}
	return false;
}

bool moveDia(){
	int i;
	for(i=0; i<3; i++)
		if(marked[i][2-i]==0){
			marked[i][2-i]=2;
			printString(moveC, ver[i][2-i][0], ver[i][2-i][1], 0.0);
			return true;
		}
	return false;
}

void moveRand(){
	int i, j;
	bool flag = true;
	while(flag==true){
		i = rand()%3;
		j = rand()%3;
		if(marked[i][j]==0){
			marked[i][j]=2;
			printString(moveC, ver[i][j][0], ver[i][j][1], 0.0);
			flag = false;
		}
	}	
}

bool computerMove(){
	int i, j;
	
	//if any row contains our 2
	for(i=0; i<3; i++){
		int c=0;
		for(j=0; j<3; j++)
			if(marked[i][j]==2)
				c++;
		if(c==2){
			if(moveInRow(i))
			return true;
		}
	}
	//if any column contains our 2
	for(i=0; i<3; i++){
		int c=0;
		for(j=0; j<3; j++)
			if(marked[j][i]==2)
				c++;
		if(c==2){
			if(moveInCol(i))
				return true;
		}
	}
	//if any diagonal contains our 2
	int c=0;
	for(i=0; i<3; i++)
		if(marked[i][i]==2)
			c++;
	if(c==2){
		if(movePri())
			return true;
	}
	c=0;
	for(i=0; i<3; i++)
		if(marked[i][2-i]==2)
			c++;
	if(c==2){
		if(moveDia())
			return true;
	}
	
	//if any row contains opposite 2
	for(i=0; i<3; i++){
		int c=0;
		for(j=0; j<3; j++)
			if(marked[i][j]==1)
				c++;
		if(c==2){
			if(moveInRow(i))
			return true;
		}
	}
	
	//if any column contains opposite 2
	for(i=0; i<3; i++){
		int c=0;
		for(j=0; j<3; j++)
			if(marked[j][i]==1)
				c++;
		if(c==2){
			if(moveInCol(i))
				return true;
		}
	}
	
	//if any diagonal contains opposite 2
	c=0;
	for(i=0; i<3; i++)
		if(marked[i][i]==1)
			c++;
	if(c==2){
		if(movePri())
			return true;
	}
	
	c=0;
	for(i=0; i<3; i++)
		if(marked[i][2-i]==1)
			c++;
	if(c==2){
		if(moveDia())
			return true;
	}
		
	moveRand();
	return true;
}

bool draw(){
	int i, j;
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			if(marked[i][j] == 0)
				return false;
	matchIsGoingOn = false;
	return true;
}
/*
void stats(){
	int matches, wins, lost;
	FILE *fp;
	fp = fopen("stats.txt", "r");
	fscanf(fp, "%d%d%d", &matches, &wins, &lost);
	printf("Number of matches played = %d\nWins = %d\nLost = %d\nDraw = %d\n\n", matches, wins, lost, matches-(wins+lost));
	fclose(fp);
<<<<<<< HEAD
}
*/
/*
=======
}*/

>>>>>>> f9318312c36dc03731085aebd36b778f665caa68
bool optionBox(GLfloat a, GLfloat b, GLfloat x, GLfloat y){
	if((x>=a && y<=b) && (x<=a+0.4 && y>=b-0.1))
		return true;
	return false;	
<<<<<<< HEAD
}*/

=======
}
/*
>>>>>>> f9318312c36dc03731085aebd36b778f665caa68
void matchOver(int vic){
	int matches, wins, lost;
	FILE *fp;
	fp = fopen("stats.txt", "r");
	fscanf(fp, "%d%d%d", &matches, &wins, &lost);
	matches++;
	if(vic==1)
		wins++;
	else if(vic==2)
		lost++;
	fclose(fp);
	fp = fopen("stats.txt", "w");
	fprintf(fp, "%d %d %d", matches, wins, lost);
	fclose(fp);
}*/

void newGame(){
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			marked[i][j]=0;
	display();
}

void mouse(int btn, int state, int ax, int ay){
	
	if(matchIsGoingOn == true && btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN && playerMove == true){
		GLfloat x = (ax/350.0)-1;
		GLfloat y = ((700-ay)/350.0)-1;
		GLfloat i, j;
		int c, d;
		bool flag = true;
<<<<<<< HEAD
		//if(optionBox(0.5, 0.9, x, y)){
		//	stats();
		//	return ;
		//}
=======
		if(optionBox(0.5, 0.9, x, y)){
			newGame();
			return ;
		}
>>>>>>> f9318312c36dc03731085aebd36b778f665caa68
		for(i=-0.6, c=0; i<0.5 && flag==true; i+=0.4, c++){
			for(j=0.6, d=0; j>-0.5; j-=0.4, d++){
				if(insideBox(i, j, x, y)){
					if(marked[d][c]==0){
						marked[d][c]=1;
						printString(moveP, ver[d][c][0], ver[d][c][1], 0.0);
						flag=false;
						break;
					}
				}
			}
		}
		if(flag==true)
			return ;
		/*for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				printf("%d ", marked[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
		if(victory(1)){
			printString(vic1, -0.2, 0.8, 0.0);
			//matchOver(1);
			return ;
		}
		if(draw()){
			printString(vic3, -0.2, 0.8, 0.0);
			//matchOver(0);
			return ;
		}
		playerMove = computerMove();
		/*for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				printf("%d ", marked[i][j]);
			}
			printf("\n");
		}*/
		if(victory(2)){
			printString(vic2, -0.2, 0.8, 0.0);
			//matchOver(2);
			return ;
		}
		if(draw()){
			printString(vic3, -0.2, 0.8, 0.0);
			//matchOver(0);
			return ;
		}
	}
}

int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("TicTacToe");
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			marked[i][j]=0;
	glutDisplayFunc(display);
	
	glutMouseFunc(mouse);
	
	glutMainLoop();
	return 0;
}
