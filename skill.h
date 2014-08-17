void Skill(unsigned char code, unsigned char lv) {
	srand(time(NULL));
	switch(code) {
	case 0: setSkill(0, rand()%3+1, 150*0.1*lv, 0);
	        strcpy(skill[code].name, "다트 플레이"); break;
	case 1: setSkill(1, 1, 10000, -10000);
	        strcpy(skill[code].name, "최후의 일격"); break;
	case 2: strcpy(skill[code].name, "웜 홀"); break;
	case 3: setSkill(3, rand()%3+1, 150*0.1*lv, 0);
	        strcpy(skill[code].name, "소드 레인"); break;
	case 4: setSkill(4, 2, 10000, -10000);
            strcpy(skill[code].name, "최후의 일격 V2"); break;
	case 5: setSkill(5, 1, (15*rand()%100+1)+10*lv, 0);
	        strcpy(skill[code].name, "다트 플레이 V2"); break;
	case 6: strcpy(skill[code].name, "웜 홀 V2"); break;
	case 7: strcpy(skill[code].name, "통과"); break;
	case 8: setSkill(7, 1, 400+10*lv, 0);
	        strcpy(skill[code].name, "파이어 토네이도"); break;
	case 9: setSkill(8, 1, 0, 50+10*lv);
	        strcpy(skill[code].name, "얼음 장벽"); break;
	case 10: strcpy(skill[code].name, "무쇠"); break;
	case 11: strcpy(skill[code].name, "로그"); break;

	}
}
