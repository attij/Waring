void mission(int code) {
	switch(code) {
	case 0: choose_partner(); break;
	case 1: fight(12, 2); break;
	}
}
void choose_partner() {
	int sel;
	enter();
	blank(9); drawline('@', 38); enter();
	blank(23); puts("파트너 선택");
	blank(9); drawline('@', 38); enter();
	enter();
	blank(9); puts("[01] 섀도우_캣");
	blank(9); puts("[특징] 단순 공격으로는 데미지 안받음");
	enter();
	blank(9); puts("[02] 파이로");
	blank(9); puts("[특징] 조금만 화나도 강한 화염을 뿜는다.");
	enter();
	blank(9); puts("[03] 아이스맨");
	blank(9); puts("[특징] 자신을 얼려 방어력 상승도 가능하다.");
	enter();
	blank(9); puts("[04] 콜로서스");
	blank(9); puts("[특징] 위기 상황에서 공격력, 방어력 200%");
	enter();
	blank(9); puts("[05] 로그");
	blank(9); puts("[특징] 상대방의 에너지를 흡수한다.");
	enter();
	blank(9); drawline('@', 38); enter();
	blank(9); printf(":"); scanf("%d", &sel);
	switch(sel) {
	case 1: monster(7); strcpy(Hero[0].name, "섀도우_캣"); break;
	case 2: monster(8); strcpy(Hero[0].name, "파이로"); break;
	case 3: monster(9); strcpy(Hero[0].name, "아이스맨"); break;
	case 4: monster(10); strcpy(Hero[0].name, "콜로서스"); break;
	case 5: monster(11); strcpy(Hero[0].name, "로그"); break;
	}
	Usr.helper_num++;
}
