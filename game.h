    int wincnt=0, defeatcnt=0;
    char Name[21];
void fight(unsigned char monster_code, unsigned char num_monster) {
	temp_save_zone();
	name(monster_code);
	extern int multiple;
    multiple=num_monster;
    extern int wincnt;
    extern int defeatcnt;
    int temp;
	monster(monster_code);
	// press enter to enjoy game
	enter();
	blank(9); drawline('@', 38); enter();
	blank(12); puts("엔터키를 누르면 게임이 시작됩니다.");
	blank(9); drawline('@', 38); enter();
	system("pause>nul");
    int playcnt=0;
	srand(time(NULL));
    if(rand()%2==0) {
    	while(1) {
    	usrturn(playcnt,num_monster);
    	heroturn(playcnt,num_monster);
    	for(temp=0;temp<Usr.helper_num;temp++) {
    	if(Usr.hp<=0 || Hero[temp].hp<=0 ) defeatcnt++; }
    	enemyturn(playcnt,num_monster);
    	for(temp=0;temp<num_monster;temp++) {
    	if(Enemy[temp].hp<=0 ) wincnt++; }
    	if(defeatcnt==Usr.helper_num+1 || wincnt==num_monster)
    	{ break; }
    	// debug
    	puts("현재 상황");
    	puts("플레이어");
    	printf("%s | %d\n", Usr.name, Usr.hp);
    	for(temp=0;temp<Usr.helper_num;temp++) {
    		printf("%s | %d\n", Hero[temp].name, Hero[temp].hp);
    	}
    	puts("적군");
    	for(temp=0;temp<num_monster;temp++) {
    		printf("%s | %d\n", Enemy[temp].name, Enemy[temp].hp);
    	}
    	//
        playcnt++;
    	}
    }
    else {
    	while(1) {
        	// debug
        	puts("현재 상황");
        	puts("플레이어");
        	printf("%s | %d\n", Usr.name, Usr.hp);
        	for(temp=0;temp<Usr.helper_num;temp++) {
        		printf("%s | %d\n", Hero[temp].name, Hero[temp].hp);
        	}
        	puts("적군");
        	for(temp=0;temp<num_monster;temp++) {
        		printf("%s | %d\n", Enemy[temp].name, Enemy[temp].hp);
        	}
        	//
    	enemyturn(playcnt,num_monster);
    	for(temp=0;temp<num_monster;temp++) {
    	if(Enemy[temp].hp<=0 ) wincnt++; }
    	usrturn(playcnt,num_monster);
    	heroturn(playcnt,num_monster);
    	for(temp=0;temp<Usr.helper_num;temp++) {
    	if(Usr.hp<=0 || Hero[temp].hp<=0 ) defeatcnt++; }
    	if(defeatcnt==Usr.helper_num+1 || wincnt==num_monster)
    	{ break; }
    	playcnt++;
    	}
    }
    if(wincnt==num_monster)
puts("win");
    else {
    	puts("defeat"); }
	temp_load_zone();
}
void usrturn(int count, int num_monster) {
	int sel;
	enter();
	blank(9); drawline('@', 38); enter();
	blank(15); printf("[%d] User\n", count);
	blank(9); drawline('@', 38); enter();
	enter();
	blank(9); printf("%s님은 누구를 공격 하시겠습니까?\n", Usr.name);
	blank(9); drawline('-', 38); enter();
	while(num_monster!=0) {
		num_monster--;
	blank(9); printf("%s %d | %d\n", Name, num_monster+1, Enemy[num_monster].hp );
	}
	blank(9); drawline('-', 38); enter();
	blank(9); printf(":"); scanf("%d", &sel);
	if(-Usr.atk+Enemy[sel-1].def<0) {
	Enemy[sel-1].hp+=-Usr.atk+Enemy[sel-1].def;
	enter();
	blank(9); drawline('@', 38); enter();
	blank(15); printf("%s damaged %d\n",Name, -Usr.atk+Enemy[sel-1].def);
	blank(9); drawline('@', 38); enter();}
	else {
		enter();
		blank(9); drawline('@', 38); enter();
		blank(15); printf("miss");
		blank(9); drawline('@', 38); enter();
	}
}
void heroturn(int count, int num_monster) {
	int sel, temp;
	temp=Usr.helper_num;
	while(temp!=0)
		temp--;
	enter();
	blank(9); drawline('@', 38); enter();
	blank(15); printf("[%d] Hero(%d)\n", count, temp);
	blank(9); drawline('@', 38); enter();
	enter();
	blank(9); printf("%s님은 누구를 공격 하시겠습니까?\n", Hero[temp].name);
	blank(9); drawline('-', 38); enter();
	while(num_monster!=0) {
		num_monster--;
	blank(9); printf("%s %d | %d\n", Name, num_monster+1, Enemy[num_monster].hp );
	}
	blank(9); drawline('-', 38); enter();
	blank(9); printf(":"); scanf("%d", &sel);
	if(-Hero[temp].atk+Enemy[sel-1].def<0) {
	Enemy[sel-1].hp+=-Hero[temp].atk+Enemy[sel-1].def;
	enter();
	blank(9); drawline('@', 38); enter();
	blank(15); printf("%s damaged %d\n",Name, -Hero[temp].atk+Enemy[sel-1].def);
	blank(9); drawline('@', 38); enter();}
	else {
		enter();
		blank(9); drawline('@', 38); enter();
		blank(15); printf("miss");
		blank(9); drawline('@', 38); enter();
	}
}
void enemyturn(int count, int num_monster) {
	while(num_monster!=0) {
		num_monster--;
		Sleep(1000);
		srand(time(NULL));
		if(defeatcnt==0) {
			printf("%d", rand()%2);
			if(rand()%2==0) {
				Usr.hp+=-Enemy[num_monster].atk+Usr.def;
			enter();
			blank(9); drawline('@', 38); enter();
			blank(15); printf("%s damaged %d\n",Usr.name, -Enemy[num_monster].atk+Usr.def);
			blank(9); drawline('@', 38); enter();}
			else {
				int temp=rand()%Usr.helper_num;
				Hero[temp].hp+=-Enemy[num_monster].atk+Hero[temp].def;
				enter();
				blank(9); drawline('@', 38); enter();
				blank(15); printf("%s damaged %d\n",Hero[temp].name, -Enemy[num_monster].atk+Hero[temp].def);
				blank(9); drawline('@', 38); enter();
			}
			}
		else {
			if(Usr.hp>0) {
				if(rand()%2+1==0) {
					Usr.hp+=-Enemy[num_monster].atk+Usr.def;
				enter();
				blank(9); drawline('@', 38); enter();
				blank(15); printf("%s damaged %d\n",Usr.name, -Enemy[num_monster].atk+Usr.def);
				blank(9); drawline('@', 38); enter();}
				else {
					int temp=rand()%Usr.helper_num;
					Hero[temp].hp+=-Enemy[num_monster].atk+Hero[temp].def;
					enter();
					blank(9); drawline('@', 38); enter();
					blank(15); printf("%s damaged %d\n",Hero[temp].name, -Enemy[num_monster].atk+Hero[temp].def);
					blank(9); drawline('@', 38); enter();
				}
				if(Usr.hp<0) {
                        srand(time(NULL));
						int temp=rand()%Usr.helper_num;
						Hero[temp].hp+=-Enemy[num_monster].atk+Hero[temp].def;
						enter();
						blank(9); drawline('@', 38); enter();
						blank(15); printf("%s damaged %d\n",Hero[temp].name, -Enemy[num_monster].atk+Hero[temp].def);
						blank(9); drawline('@', 38); enter();
					}
				}
			}
		}
		}
