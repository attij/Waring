FILE *db;
void data_load() {
db=fopen("C:\\WARing\\db.txt", "r");
if((db=fopen("C:\\WARing\\db.txt", "r"))!=NULL) {
fscanf(db,"%s %d %d %d %d %d %d %d %d %d\n", Usr.name, &Usr.job_code, &Usr.skill_code, &Usr.lv, &Usr.exp, &Usr.atk, &Usr.def, &Usr.hp, &Usr.money, &Usr.helper_num);
printf("%s %d %d %d %d %d %d %d %d %d\n", Usr.name, Usr.job_code, Usr.skill_code, Usr.lv, Usr.exp, Usr.atk, Usr.def, Usr.hp, Usr.money, Usr.helper_num);
int temp=Usr.helper_num;
while(temp!=0) {
	temp--;
	fscanf(db, "%s %d %d %d %d %d %d %d\n", Hero[temp].name, &Hero[temp].job_code, &Hero[temp].skill_code, &Hero[temp].lv, &Hero[temp].exp, &Hero[temp].atk, &Hero[temp].def, &Hero[temp].hp);
	printf("%s, %d, %d, %d, %d, %d, %d, %d\n",Hero[temp].name, Hero[temp].job_code, Hero[temp].skill_code, Hero[temp].lv, Hero[temp].exp, Hero[temp].atk, Hero[temp].def, Hero[temp].hp);
}
fclose(db);}
else setup();
}
void data_save() {
db=fopen("C:\\WARing\\db.txt", "w+");
fprintf(db,"%s %d %d %d %d %d %d %d %d %d\n", Usr.name, Usr.job_code, Usr.skill_code, Usr.lv, Usr.exp, Usr.atk, Usr.def, Usr.hp, Usr.money, Usr.helper_num);
while(Usr.helper_num!=0) {
	Usr.helper_num--;
	fprintf(db, "%s %d %d %d %d %d %d %d\n", Hero[Usr.helper_num].name, Hero[Usr.helper_num].job_code, Hero[Usr.helper_num].skill_code, Hero[Usr.helper_num].lv, Hero[Usr.helper_num].exp, Hero[Usr.helper_num].atk, Hero[Usr.helper_num].def, Hero[Usr.helper_num].hp);
}
fclose(db);
}
void temp_save_zone() {
	Tmp[0].hp=Usr.hp;
	int i;
	for(i=1;i<=Usr.helper_num;i++) {
	Tmp[i].hp=Hero[i-1].hp;
	}
}
void temp_load_zone() {
	Usr.hp=Tmp[0].hp;
	int i;
	for(i=1;i<=Usr.helper_num;i++) {
	Hero[i-1].hp=Tmp[i].hp;
	}
}
