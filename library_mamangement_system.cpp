#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct book{
    string name,title,book_code,author,ISBN;
    int year,book_id;
};
struct bookcopy{
    int copy_id,book_id;
    string condition,status,shelf_location;
};

struct member{
   int member_id,semester;
   string name,department,Email,membership_status,roll_number,phone;
};
 struct issuerecord{
int Member_id,book_id;
string issue_date, return_date, status; 
};
    struct reservation{
        int member_id,book_id;
        string Reservation_date , Reservation_status;
    };
    struct fine{
        int member_id,book_id;
        double fine_amount;
        string fine_status;
    };
class BookManager{
    public:
    book o;
    vector<book> books;
    
    void add_book(){
        book b;
        cout<<"what is title of book?:-"<<endl;
        cin>>b.title;
        cout<<"what is book ID:- "<<endl;
        cin>>b.book_id;
        cout<<"who is author?:- "<<endl;
        cin>>b.author;
        cout<<"what is ISBN?:-"<<endl;
        cin>>b.ISBN;
        books.push_back(b);
        
 }

  void search_book(){
    bool found = false;

     int id;
     cout<<"what is book id? :- ";
     cin>>id;
     for(auto it = books.begin(); it != books.end(); it++){
        if((*it).book_id == id)
        {
            found = true;
          cout<<"book id:- "<< (*it).book_id<<endl;
          cout<<"author:- "<< (*it).author<<endl;
          cout<<"ISBN:-  "<< (*it).ISBN<<endl;
          cout<<"title:- "<<(*it).title<<endl; 
            
        }
        if(found == false) {
            cout<<"Book not found !"<<endl;
            return;
        }
     }

}
  
  void delete_books(){
    bool found = false;
    int delete1;
    cout<<"what book you want to delete (ID);- "<<endl;
    cin>>delete1;
   //for(auto it = books.begin(); it != books.end(); it++){  this was my own idea its not work because its check only first condition like if first book is not match so its skipp all books
   auto it = books.begin();
   while (it != books.end()){
         if((*it).book_id == delete1){
            found = true;
           it =  books.erase(it);
           cout<<"Book Removed succefully !"<<endl;
         }
         else {
            it++;
         }
         if (found == false){
            cout<<"Book not found"<<endl;
         }
    }
  }

  void display_books(){
     cout<<"================= ALL BOOKS ================= ";

     for (auto it = books.begin(); it != books.end(); it++){
     cout<< (*it).book_id<<endl;
     cout<< (*it).author<<endl;
     cout<< (*it).ISBN<<endl;
     cout<< (*it).title<<endl; };

  }
  void update_books(){
     int update;
     bool found = false;
     cout<<"Which book you want to update:- "<<endl;
     cin>>update;
     auto it = books.begin();
    while(it != books.end()){
        if((*it).book_id == update){
            found = true;
            cout<<"what is name of author that you want to update:- ";
            cin>>it->author;
            cout<<"what is ISBN that you want to update:- ";
            cin>>it->ISBN;
            cout<<"what is title of book that you want to update :- ";
            cin>>it->title;
            cout<<"Book updated !"<<endl;
            break;
        }
        else{
            it++;
        }
        
    }
    if(found == false){
            cout<<"Book not found"<<endl;
        }
}

void search_bookcopy(){}
  
void exit(){
    cout<<"Exiting... Cutie";
}


void save_books(){
    
   ofstream fout;
   fout.open("Book.txt");
   for(auto it = books.begin(); it != books.end(); it++){
   fout<<it->title<<endl;
   fout<<it->author<<endl;
   fout<<it->book_id<<endl;
   fout<<it->ISBN<<endl;
   }
   fout.close();


}

void load_books(){
book b;
    ifstream fin;
    fin.open("Book.txt");
    if(!fin){
    cout<<"Unable to open Book.txt";
    return;
}
    books.clear();
    while(getline(fin,b.title) && getline(fin,b.author) && fin>>b.book_id && fin.ignore() && getline(fin,b.ISBN)){
            books.push_back(b);

    }
 fin.close();
    }

};

class MemberManager{
    public:
    vector<member>members;
    int counter_id = 1001;
    void add_member(){
    member m;
            
    m.member_id = counter_id;
    counter_id++;
    cout << "Your Member ID is: " << m.member_id << endl;

    cout << "Enter member name: "<<endl;
    cin >> m.name;

    cout << "Enter department: "<<endl;
    cin >> m.department;

    cout << "Enter semester: "<<endl;
    cin >> m.semester;

    cout << "Enter roll number: "<<endl;
    cin >> m.roll_number;

    cout << "Enter phone number: "<<endl;
    cin >> m.phone;

    cout << "Enter email: "<<endl;
    cin >> m.Email;

    m.membership_status = "Active";

    members.push_back(m);

    cout << "Member registered successfully!" << endl;

    }


    void search_member(){
        int member_id;
        cout<<"Enter the member id :- "<<endl;
        cin>>member_id;
        bool found = false;
        for (auto it = members.begin(); it != members.end(); ){
            if((*it).member_id==member_id){
                    found = true;
                    cout<<"department: "<<it->department<<endl;
                    cout<<"name: "<<it->name<<endl;
                    cout<<"membership status:"<<it->membership_status<<endl;
                    cout<<"phone no: "<<it->phone<<endl;
                    cout<<"roll number:"<<it->roll_number<<endl;
                    cout<<"semster: "<<it->semester<<endl;
                    cout<<"this is member details" <<endl;
                    break;
            }
            else {
                it++;
            }
        }
        if(found == false){
            cout<<"member not found";
        }


    }

    void update_member_details(){
        bool found = false;
        int update1;
    cout<<"what member you want to update (ID):- ";
    cin>>update1;
      auto it = members.begin();
      while(it != members.end()){
        if((*it).member_id==update1){
            found = true;
        cout<<"what is name that you want to update:- ";
        cin.ignore();
        getline(cin,it->name);
        cout<<"what is department that you want to update:- ";
       cin>>it->department;
        cout<<"what is Email that you want to update:- ";
        cin>>it->Email;
        cout<<"what is semster that you want to update:- ";
        cin>>it->semester;
        cout<<"what is phone no. that you want to update:- ";
        cin>>it->phone;
    break;}
        else {
            it++;
        }
    }if(found == false){
        cout<<"Member not found !";
    }
    }


    void deactivate_membership(){
           int deactive;
           bool found = false;
           cout<<"member id:-";
           cin>>deactive;
            auto it = members.begin();
            while(it != members.end()){
              if((*it).member_id==deactive){
                      found = true;
                    it->membership_status = "Inactive!";
                    cout<<"membership status Inactive succefully !";
                    break;
                
    
            }
                else{
                    it++;}
                                }
                                if(found ==false){
                                    cout<<"member not found:( ";
                                }
                             }


    
    void display_members(){
    cout<<"================== ALL Member ====================";
    if (members.empty()) {
    cout << "No members registered!" << endl;
    return;
}
    for(auto it = members.begin(); it != members.end(); it++){
        cout << "Name: " << it->name << endl;
        cout << "Member ID: " << it->member_id << endl;
        cout << "Department: " << it->department << endl;
        cout << "Semester: " << it->semester << endl;
        cout << "Email: " << it->Email << endl;
        cout << "Phone: " << it->phone << endl;
        cout << "Roll Number: " << it->roll_number << endl;
        cout << "Membership Status: " << it->membership_status << endl;
            cout << "---------------------------------------" << endl;
    }

  }
  

  void save_members(){

    ofstream fout;
    fout.open("member.txt");
    for(auto it = members.begin(); it != members.end(); it++){
         fout<<it->name<<endl;
         fout<<it->member_id<<endl;
         fout<<it->department<<endl;
         fout<<it->semester<<endl;
         fout<<it->Email<<endl;
         fout<<it->roll_number<<endl;
         fout<<it->phone<<endl;
         fout<<it->membership_status<<endl;
         }
         fout.close();

}
 void load_members(){
      member m; // koi bhi variable use kar skta hai m ki jagah
    ifstream fin;
    fin.open("member.txt");
    if(!fin){
        cout<<"error file does't open";
        return;
    }
    members.clear();
    while(getline(fin,m.name) && fin>>m.member_id && fin.ignore() && getline(fin,m.department) && fin>>m.semester && fin.ignore() && getline(fin,m.Email) && getline(fin,m.roll_number) && getline(fin,m.phone) && getline(fin,m.membership_status) ){
         members.push_back(m);
    }
    for(auto it = members.begin(); it != members.end(); it++){
    if(it->member_id >= counter_id){
        counter_id = it->member_id + 1;
    }
}
    fin.close();
}
};
class circulationManager{
    public:
    MemberManager m;
     issuerecord issue;
    vector<issuerecord>records;
    
   
 
    void issue_books(BookManager &bo, MemberManager &m) {
        

    int memberid, bookid;

    cout << "Enter member ID: ";
    cin >> memberid;

    cout << "Enter book ID: ";
    cin >> bookid;

    // 1. Check member
    bool memberFound = false;

    for (auto it = m.members.begin(); it != m.members.end(); it++) {
        if (it->member_id == memberid) {
            memberFound = true;
            break;
        }
    }

    if (memberFound == false) {
        cout << "Member not found!" << endl;
        return;
    }

    // 2. Check book
    bool bookFound = false;

    for (auto it = bo.books.begin(); it != bo.books.end(); it++) {
        if (it->book_id == bookid) {
            bookFound = true;
            break;
        }
    }

    if (bookFound == false) {
        cout << "Book not found!" << endl;
        return;
    }

    // 3. Check availability
    bool available = true;

    for (auto it = records.begin(); it != records.end(); it++) {
        if (it->book_id == bookid && it->status == "Issued") {
            available = false;
            break;
        }
    }

    if (available == false) {
        cout << "Book is already issued!" << endl;
        return;
    }

    // 4. Create issue record
    issuerecord issue;

    issue.Member_id = memberid;
    issue.book_id = bookid;

    cout << "Enter issue date: ";
    cin >> issue.issue_date;

    cout << "Enter return date: ";
    cin >> issue.return_date;

    issue.status = "Issued";

    // 5. Save record
    records.push_back(issue);

    cout << "Book issued successfully!" << endl;
}



 void return_books(){
    int memberid,bookid;
    bool found = false;
    cout<<"what uis meber id:- ";
    cin>>memberid;
    cout<<"what is book id: -";
    cin>>bookid;
    for(auto it = records.begin();it != records.end();it++ ){
        if(it->Member_id==memberid && it->book_id==bookid &&it->status=="Issued"){
            found = true;
            it->status = "Returned";
            cout<<"Book return succefully !";
            break;
    }
     }
    
    if(found == false){
            cout<<"No active issue record found !";
            }
}

void renew_books(){
    int memberid,bookid;
    bool found = false;
    
      cout<<"what your is member id:- ";
      cin>>memberid;
      cout<<"what is book id: -";
      cin>>bookid;
      for(auto it = records.begin();it != records.end();it++ ){
      if(it->Member_id==memberid && it->book_id==bookid && it->status=="Issued")
      {   
        found = true;
        cout<<" what is new date :- "<<endl;
          cin>>it->return_date;
          cout<<"Book renewed successfully!";   
          break; 
        }
    }
      if(found == false){
        cout<<"book not found in record";
      } 
    }

   void check_borrowing_limits(){
    int memberid;
    
    int count = 0;
    cout<<"what is your member ";
    cin>>memberid;
    for(auto it = records.begin();it != records.end();it++ ){
        if(it->Member_id==memberid && it->status=="Issued"){
            
              count++;

        }
     
       }
   if(count == 0){
    cout<<"No active borrowed books.!";
   }
   else if(count == 3){
    cout<<"Borrowing limit reached.!";
   }
   else if(count < 3){
   cout<<"you can borrow"<< 3-count<<" more book !s";
   
   }
  else{
    
    cout<<"limit has been exceeded.!";
   }
   }

   void save_circulation(){
    issuerecord i;
            ofstream fout;
            fout.open("circulation.txt");
            for( auto it = records.begin(); it != records.end(); it++){
                 fout<<it->book_id<<endl;
                 fout<<it->Member_id<<endl;
                 fout<<it->issue_date<<endl;
                 fout<<it->return_date<<endl;
                 fout<<it->status<<endl;
                                       
                }
                  fout.close();
   }

   void load_circulatiom(){
    issuerecord i;
    ifstream fin;
     
    fin.open("circulation.txt");
    if(!fin){
    cout<<"Unable to open circulation.txt";
    return;
}    records.clear();
    while(fin>>i.book_id && fin>>i.Member_id && fin.ignore()  && getline(fin,i.issue_date) && getline(fin,i.return_date) && getline(fin,i.status) ){
                      
        records.push_back(i);

    }
    fin.close();
   }
};



class ReservationManager{
    public:
    vector<reservation> reserve;



    void Reserve_books(BookManager &bo,MemberManager &m,circulationManager &c){
        reservation r;
        int memberid,bookid;
        bool memberFound = false;
        cout<<"what is your member id :-";
        cin>>memberid;
        cout<<"what is book id :- ";
        cin>>bookid;
        for(auto it = m.members.begin(); it != m.members.end();it++ ){
              if(it->member_id==memberid){
                memberFound = true;
                break;                    
            }
        }
        if(memberFound==false) {
                cout<<" Member not found ! "<<endl;
                return;
            }
            bool bookfound =  false;
        for(auto it = bo.books.begin(); it != bo.books.end(); it++){

               if(it->book_id==bookid){
                       bookfound = true;
                       break;

               }
        }
        if(bookfound==false){
            cout<<"book not found !";
            return;

        }
        bool foundissued = false;
        for(auto it = c.records.begin(); it != c.records.end(); it++){
            if(it->book_id == bookid && it->status=="Issued"){
                foundissued = true;
                break;
            }
        }
        if(foundissued==false){
            cout<<" Book is currently available";
            return;
        }
        

        r.book_id = bookid;
        r.member_id = memberid;
        r.Reservation_status = "Active";
        cout<<"what is date";
        cin>>r.Reservation_date;
         reserve.push_back(r);
         cout<<" Book reserved succefully !";


}
    void Cancel_reservations(MemberManager &m){
        int memberid,bookid;
    cout<<" what is member id:- ";
    cin>>memberid;
    cout<<"what is book id:- ";
    cin>>bookid;
    bool memberfound = false;
    for(auto it = m.members.begin(); it != m.members.end(); it++){
        if(it->member_id==memberid){
            memberfound = true;
            break;

        }
        
    }
    if(memberfound == false){
        cout<<"member not exist !";
        return;

    }
      bool foundreserve = false;
      for(auto it = reserve.begin();it != reserve.end(); it++){
         if (it->member_id == memberid &&
        it->book_id == bookid &&
        it->Reservation_status == "Active"){

        it->Reservation_status = "Cancelled";
         foundreserve = true;

        cout << "Reservation cancelled successfully!";
        break;
    }
        }
        if ( foundreserve == false) {
    cout << "Active reservation not found!";
}
      }
    
    void Manage_waiting_queues(){
        for(auto it = reserve.begin(); it != reserve.end(); it++){
            if(it->Reservation_status == "Active"){
     cout<<" Member id :-"<<it->member_id<<endl;
     cout<<"Boook id:- "<<it->book_id<<endl;
     cout<<"Reservation status:- "<<it->Reservation_status<<endl;
     cout<<"Reservation date:- "<<it->Reservation_date<<endl;
     
            }
    }

    }
    void Process_reservations_when_copies_become_available(){
        int returnbook;
        cout<<"what is id of bool:- ";
        cin>>returnbook;
        bool activeReservationFound = false;
        for(auto it = reserve.begin(); it != reserve.end(); it++){

              if(it->book_id==returnbook && it->Reservation_status == "Active"){
                activeReservationFound = true;
            cout<<"member id"<<it->member_id;
            it->Reservation_status = "Notified";
            cout << "Book is available. Member has been notified!" << endl;

            break;
        }


        }
        if(activeReservationFound==false){
            cout<<"No active reservations for this book.";
            return;
        }
    }

    void save_reserve(){
         ofstream fout;
         fout.open("Reservation.txt");
         for(auto it = reserve.begin();it != reserve.end(); it++ ){
            fout<<it->book_id<<endl;
            fout<<it->member_id<<endl;
            fout<<it->Reservation_date<<endl;
            fout<<it->Reservation_status<<endl;
         }
         fout.close();

    }

void load_reserve(){
    reservation r;
    ifstream fin;
    fin.open("Reservation.txt");
  
    if(!fin){
    cout<<"Unable to open Reservatiom.txt";
    return;}
    reserve.clear();
    while(fin>>r.book_id && fin>>r.member_id && fin.ignore() && getline(fin,r.Reservation_date) && getline(fin,r.Reservation_status)){
        reserve.push_back(r);
    }
    fin.close();


       
}    

};

class FineManager{
    
    public:
    
    vector<fine>fines;

    void Calculate_late_return_fines(){
            fine f;

        int memberid,bookid,days;
        cout<<"what is member id:-";
        cin>>memberid;
        cout<<"what is book id";
        cin>>bookid;
        cout<<"how many days late the book waa returned ?:-";
        cin>>days;
        if(days<=0){
            cout<<"invalid";
            return;
        }
        cout<<"The fine is "<<days*10<<"Rs";
        
        
             f.member_id = memberid;
            f.book_id = bookid;
             f.fine_status = "unpaid";
             f.fine_amount = days*10;
            
             fines.push_back(f);
}

     void Check_unpaid_fines(){
         bool amountfine = false;

            for(auto it = fines.begin(); it != fines.end(); it++){
             if(it->fine_status=="unpaid"){
                amountfine= true;
                 cout<<"Book id:- "<<it->book_id<<endl;
                 cout<<"member id:- "<<it->member_id<<endl;
                 cout<<"fine amount:- "<<it->fine_amount<<endl;
                 cout<<"fine status:- "<<it->fine_status<<endl;

      }
  }
    if(amountfine==false){
      cout<<"No unpaid fines found.";
             return;
                }

}

    void Record_payments(){
        int memberid,bookid;
        bool paidstatus = false;
        cout<<"what is member :- ";
        cin>>memberid;
        cout<<"what is book id :-";
        cin>>bookid;
        for(auto it = fines.begin(); it != fines.end(); it++){
            if(it->book_id==bookid && it->member_id==memberid && it->fine_status=="unpaid")
            {  
                paidstatus = true;
                 it->fine_status="paid";
                 cout<<"Payment paid successfully !";
                break;

            }
        }
        if(paidstatus==false){
            cout<<"not yet paid !";
            return;
        }
        
}

    void save_fines(){
        ofstream fout;
        fout.open("fines.txt");
        for(auto it = fines.begin(); it != fines.end(); it++){
            fout<<it->member_id<<endl;
             fout<<it->book_id<<endl;
             fout<<it->fine_amount<<endl;
             fout<<it->fine_status<<endl;
             

        }
        fout.close();

    }

    void load_fines(){
    ifstream fin;
    fine f;
    fin.open("fines.txt");
    if(!fin){
        cout<<"error ! file not open fines.txt";
        return;
    }
    fines.clear();
    while(fin>>f.member_id && fin>>f.book_id && fin>>f.fine_amount && fin.ignore() && getline(fin, f.fine_status)){
      fines.push_back(f);  

    }
    fin.close();


    }

};
class AuthenticationManager{

void login(){}

void verify_credentials(){}

};
// class libary{
//   private:
//   BookManager bookmanager;
//   MemberManager membermanager;
//   circulationManager circulationmanager;
//   ReservationManager reservationmanager;
//   FineManager finemanager;
//   AuthenticationManager  authenticationmanager;

//   public:
//   void managebooks(){
//     bookmanager.add_book();
//   }

   

// };

 int main(){
   // libary mylibary;
    // mylibary.managebooks();
    BookManager bo;
    MemberManager m;
    circulationManager ci;
    ReservationManager r;
    FineManager f;
    bo.load_books();
    m.load_members();
    ci.load_circulatiom();
    r.load_reserve();
    f.load_fines();

    
    
    int c = -1;
    while(c !=0){

    cout<<endl<<"========================= Main Menu ========================="<<endl;

    cout<<endl<<"============== Book Manager ==============="<<endl;
    cout<<"1. add_book:"<<endl;

    cout<<"2. search_book:"<<endl;
    cout<<"3. delete_books:"<<endl;
    cout<<"4. display_books:"<<endl;
    cout<<"5. update_books:"<<endl;
    cout<<"6. search_bookcopy:"<<endl;

    cout<<endl<<"============ Member details ==============="<<endl;




    cout << "7. Add Member:" << endl;
    cout << "8. Search Member:" << endl;
    cout << "9. Update Member Details:" << endl;
    cout << "10. Deactivate Membership:" << endl;
    cout << "11. Display Members:" << endl;



    cout<<endl<<"============ circulation Manager ==============="<<endl;


    cout << "12. Issue Book" << endl;
    cout << "13. Return Book" << endl;
    cout << "14. Renew Book" << endl;
    cout << "15. Check Borrowing Limits" << endl;
    



    cout <<endl<< "============= Reservation Management ==============" << endl;

    cout << "16. Reserve Book" << endl;
    cout << "17. Cancel Reservation" << endl;
    cout << "18. Manage Waiting Queues" << endl;
    cout << "19. Process Reservations When Book Becomes Available" << endl;

cout<<endl<<"================= Fine Manager ================"<<endl;

    cout << "20. Calculate Late Return Fine\n";
    cout << "21. Check Unpaid Fines\n";
    cout << "22. Record Fine Payment\n";
    cout << "0. Exit\n";



    cin>>c;
    switch (c){
     case 1:
     bo.add_book();
   break;
     case 2:
     bo.search_book();
     break;
     case 3:
     bo.delete_books();
     break;
     case 4:
     bo.display_books();
     break;
     case 5:
     bo.update_books();
     break;
     case 6:
     bo.search_bookcopy();
     break;
    
    case 7:
        m.add_member();
        break;

    case 8:
        m.search_member();
        break;

    case 9:
        m.update_member_details();
        break;

    case 10:
        m.deactivate_membership();
        break;

    case 11:
        m.display_members();
        break;

case 12:
    ci.issue_books(bo, m);
    break;

case 13:
    ci.return_books();
    break;

case 14:
    ci.renew_books();
    break;

case 15:
    ci.check_borrowing_limits();
    break;

    case 16:
    r.Reserve_books(bo, m, ci);
    break;

case 17:
    r.Cancel_reservations(m);
    break;

case 18:
    r.Manage_waiting_queues();
    break;

case 19:
    r.Process_reservations_when_copies_become_available();
    break;

    case 20:
    f.Calculate_late_return_fines();
    break;

case 21:
    f.Check_unpaid_fines();
    break;

case 22:
    f.Record_payments();
    break;

case 0:
    bo.save_books();
    m.save_members();
    ci.save_circulation();
    r.save_reserve();
    f.save_fines();
    cout << "Books saved. Program exiting...";
    break;

         
    default:
    cout<<"invaild output;";
    }}






}