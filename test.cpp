#include <iostream>
#include <string.h>
using namespace std;
class Employee
{
    // Bvh gishvvn ugugdlvvdiig private -aar zarlana
    private:
    //ajilchnii dugaar
    int number;
    //ajilchnii ner
    char name[20];
    //alban tushaal
    char position[10] ;
    //ajilsan tsag
    float jobtime;
    //ajilchnii tsalin
    float salary;

    // Zahirliin tsalin bodoh gishvvn punkts
    float bossSalary(void);

    public:
    // Garaanii utga onooh gishvvn punkts
    void startdata(void);
    // Garaas ugugdul unshih gishvvn punkts
    void setdata(void);
    // Ugugdliin utgiig haruulah g/punkts
    void showdata(void);
    // salary g/ogogdliin utgiig butsaah gishvvn punkts
    float getpay();
    // ajilchdiin tsalin tootsooloh g/punkts
    float calSalary(void);
    // nemelt tsag tootsoh g/punkts
    int addJob(float);
};
// garaanii utga onooh g/punktsiin todorhoilson heseg
void Employee::startdata(void){
	//numberd 0 utga onoono
    number = 0;
    //name d strcpy punktseer hooson utga onoono
    strcpy(name," ");
    //position strcpy punktseer ajiltan gesen utga onoono
    strcpy(position,"ajiltan");
    //ajilsan tsagt 0 gesen utga onoono
    jobtime = 0;
}
//garaas utga awah punktsiin todorhoilson heseg
void Employee::setdata(void){
	//ajilchinii number garaas awah
    cout << "Number: ";
    cin >> number;
    //ajilchnii ner garaas awah
    cout << "Name: ";
    cin >> name;
    //alban tushaal garaas awah
    cout << "Position: ";
    cin >> position;
    //ajilsan tsag garaas awah 1-8 hoorond bna
    cout << "Jobtime: ";
    cin >> jobtime;

}
//ajilchnii medeelel haruulah gishvvn punkts todorhoilson heseg
void Employee::showdata(void){
    cout << "Number = " << number << "\n";
    cout << "Name = " << name << "\n";
    cout << "Position = " << position << "\n";
    cout << "Salary = " << salary << endl;
}
//tsalin tootsoh gishvvn punkts
float Employee::calSalary(void){
	//boss gesen temdegten hvsnegt vvsgene
    char boss[10];
    //vvsgesen  boss hvnegtend zahiral gese nutgiig huulna
    strcpy(boss,"zahiral");
    //ajilsan tsag ilvv bgaa esehiig shalgana
    if(addJob(jobtime) == 1)
    	//ajilsan tsag ilvv  bwal jobtime iig 1 eer nemegdvvlne
        jobtime++;
    //garaas unshsan position(alban tushaal) boss hvsnegtiinhtiin utgatai adil esehiig shalgana
    if(strcmp(position,boss) == 0)
    	//adil bwal zahirliin tsalin bodoh g.punktsiig duudna
        bossSalary();
    //vgvi bol hewiin ajilchnii tsalin bodoj salary-d utgiig onoono
    else
    	//niit awah tsalin / ajillah niit tsag * (ajilsan honog* ajilsan tsag)
        salary = 300000 / 168 * (21*jobtime);
}
//zahirliin tsalin bodoh gishvvn punkts
float Employee::bossSalary(void){
	//niit awah tsalin / ajillah niit tsag * (ajilsan honog* ajilsan tsag)
    salary = 500000 / 168 * (21*jobtime);
}
//nemelt tsag tootsoh g.punkts
int Employee::addJob(float jobtime){
	// odort ajilsan tsag ni 9 oos ih 24 oos baga bwal 1 iig butsaana esreg tohioldold 0 iig butsaana
    return (jobtime > 9 && jobtime < 24);
}
//ajilchnii tsalind handah g.punkts
float Employee::getpay(){
	//punkts duudsan ved tuhain ajilchnii salary-g butsaana
    return salary;
}
int main()
{
	//obiekten hvsneg vvsgene, mun engiin empk nertei obiekt vvsgene
    Employee emp[10],empk;
    //ashiglah parametervvdee zarlana
    int n, k, i, j;
    //n ajiltnii toog garaas unshina
    cout << "Oruulah ajiltanii too:";
    cin >> n;
    //0 -ees n hvrtel ajiltanii medeelel garaas unshina
    for(k = 0; k < n; k++){
    	//emp[k] dugaar ajiltnii medeelliig unshina
        emp[k].setdata();
        //emp[k] dugaar ajiltnii tsalin tootsoolon salary -d ni utgiig ni hadgalna
        emp[k].calSalary();
    }
   //bubble sort erembelelt
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++)
        //omnoh ajiltnii tsalin daraagiin ajiltnii tsalingaas baga bwal swap buyu bair solih uildel hiine
            if(emp[i].getpay() < emp[j].getpay()){
            	//swap hiih vildel
                empk = emp[i];
                emp[i] = emp[j];
                emp[j] = empk;
            }
    }
    //print jagsaalt
    cout << "Jagsaalt:" << endl;
    //0 ees n hvrtel eremblegdsen ajilnii medeelliig hewlene
    for(k = 0; k < n; k++){
        cout << k+1 <<":\n";
        //emo[k] dugaar ajiltnii medeelliig showdata g.punktseer hewlene
        emp[k].showdata();
    }
    return 0;
}
