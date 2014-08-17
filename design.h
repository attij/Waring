void drawline(char symbol, unsigned char length) {
	while(length!=0) {
		printf("%c", symbol);
		length--;
	}
}
void enter() {
	printf("\n");
}
void blank(unsigned char length) {
	while(length!=0) {
		printf(" ");
		length--;
	}
}
void setconsole() {
	SetConsoleTitle("Legion Of Heroes");
	system( "mode con lines=31 cols=55" );
}
