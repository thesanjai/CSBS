#include<iostream>
#include<iomanip>
#include<string>
using namespace std;


class PATIENT{

 protected:
    int Patient_ID;
    string Patient_name;
    int Age;
    string Disease;
    string Blood_group;
    int Doctor_ID;

 public:
    
    
    PATIENT(int Patient_ID,string Patient_name,int Age,string Disease, string Blood_group,int Doctor_ID){
        this->Patient_ID=Patient_ID;
        this->Patient_name=Patient_name;
        this->Age=Age;
        this->Disease=Disease;
        this->Blood_group=Blood_group;
        this->Doctor_ID=Doctor_ID;
    }
};

class DOCTOR{
    protected:
    int Doc_id;
    string Doctor_name;
    string Specialization;

    public:
    
    DOCTOR(int Doctor_ID,string Doctor_name,string Specialization){
        this->Doc_id=Doctor_ID;
        this->Doctor_name=Doctor_name;
        this->Specialization=Specialization;
    }

    void Doctor_display(){
        cout<<"\nDETAILS OF THE DOCTOR\n";
        cout<<"DOCTOR ID: "<<Doc_id<<endl;
        cout<<"DOCTOR NAME: "<<Doctor_name<<endl;
        cout<<"SPECIALIZATION: "<<Specialization<<endl<<endl;
    }
};

class TREATMENT:virtual public PATIENT,virtual public DOCTOR{

    public:
    
   

    TREATMENT(int pid,string pname,int age,string disease,string bgroup,int did,int docid,string docname,string spl):
    PATIENT(pid,pname,age,disease,bgroup,did),
    DOCTOR(docid,docname,spl){};
        
    //I cann't use this function in PATIENT class because, PATIENT class don't have the access for the doctor name.
    void patient_display(){
        cout<<"\nDETAILS OF THE PATIENT:\n";
        cout<<"PATIENT ID: "<<Patient_ID<<endl;
        cout<<"PATIENT NAME:"<<Patient_name<<endl;
        cout<<"PATIENT NAME: "<<Age<<endl;
        cout<<"DOCTOR ID: "<<Doctor_ID<<endl;
        cout<<"DOCTOR NAME: "<<Doctor_name<<endl<<endl;

    }
        
        void search(int doc_id,int pat_id){
            if(doc_id==Doc_id and pat_id==Patient_ID ){
                patient_display();
            }
       
        }

        void search(int doc_id){
            if(doc_id==Doc_id){
                patient_display();
            }
        }
        friend void search(string name,TREATMENT t[],int treatment_size);
};


void search(string name,TREATMENT t[],int treatment_size){
           
           for(int i=0;i<treatment_size;i++){
            if(t[i].Patient_name==name)
                t[i].Doctor_display();
           }
}
int main(){
   

  TREATMENT T[]={
    TREATMENT(1,"SANJAI SK",19,"Fever","B+",901,901,"Dr.SANJAI KUMAR","E.N.T"),
    TREATMENT(2,"TOM",25,"JAUNDICE","AB+",100,100,"Dr.HEMALTHA","GENERAL"),
    TREATMENT(3,"JERRY ",19,"EAR PAIN","B-",201,201,"Dr.SIVAKUMAR","OPTHOMOLOGY"),
    TREATMENT(4,"JACKIEE CHAN",35,"EYE PAIN","O+",222,222,"Dr.VOSHINI","ORTHOPEDIC"),
    TREATMENT(5,"JULLY",12,"COUGH & COLD","A+",100,100,"Dr.HEMALTHA","GENERAL"),
    TREATMENT(6,"DORA",18,"SMALL POX","B+",100,100,"Dr.HEMALTHA","GENERAL"),
    TREATMENT(7,"BUJJI",30,"SPRAIN","AB-",901,901,"Dr.SANJAI KUMAR","E.N.T")
   };

    int treatment_size=sizeof(T)/sizeof(T[0]);

    cout<<"\n\n*******HOSPITAL MANGEMENT SYSTEM********\n";
    cout<<setw(20)<<"WELCOME"<<endl<<endl;
    
    int choice;
    string pname;
    
    do{
         cout<<"1-Search for Patient & Doctor Deatails."<<endl;
         cout<<"2-Search for patients of a Particular Doctor."<<endl;
         cout<<"3-Search for Doctor of a Particular Patient."<<endl;
         cout<<"4-EXIT"<<endl;
         cout<<"Enter your choice: ";
         cin>>choice;
        switch (choice){

            case 1:
                   int pid,did;
                   cout<<"Available Patient ID's : 1,2,3,4,5,6,7"<<endl;
                   cout<<"Available Doctor ID's : 901,100,201,222,300"<<endl;
                   cout<<"Enter the Patient ID: ";
                   cin>>pid;
                   cout<<"Enter the Doctor Id: ";
                   cin>>did;
                     for(int i=0;i<treatment_size;i++){
                          T[i].search(did,pid);
                     }
                    break;

            case 2:
                    int Did;
                    cout<<"Available Doctor ID's=901,100,201,222,300"<<endl;
                    cout<<"Enter the Doctor ID : ";
                    cin>>Did;
                     for(int i=0;i<treatment_size;i++){
                         T[i].search(Did);
                        }
                    break;
            case 3:
                   
                    cout<<"Available Patient Name's : SANJAI SK,TOM,JERRY,JACKIEE CHAN,JULLY,DORA,BUJJI"<<endl;
                    cout<<"Enter the Name of the Patient: ";
                    cin>>ws;//to clear buffer,like cin.ignore();
                    getline(cin,pname);
                    search(pname,T,treatment_size);
                    break;
            case 4:
                    cout<<"\nExited Sucessfully!!";
                    break;
            default:
                    cout<<"\nERROR!!!!!,Ivalid choice Please input the valid choice.\n\n";
                    break;
         }
    }while(choice!=4);
  return 0;
}

 