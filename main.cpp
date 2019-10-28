#include <iostream>
#include <vector> 

using namespace std; 

string get_top(int number,int s){
    string temporal="";
    if (number==1 || number==4){
        for (int i=0;i<s+2;i++){
            temporal+=" ";
        }
        return temporal;
    }else{
        temporal+=" ";
        for (int i=0;i<s;i++){
            temporal+="-";
        }
        temporal+=" ";
        return temporal;
    }
}

string get_middle1(int number, int s){
    string temporal;
    if (number==4 || number==5 || number==6 || number==8 || number==9 || number==0 ){
        temporal+="|";
    }else{
        temporal+=" ";
    }
    for (int i=0;i<s;i++){
        temporal +=" ";
    }
    if(number==1 ||number==2 || number==3 ||number==4 || number==7 || number==8 || number==9 || number==0 ){
        temporal+="|";
    }else{
        temporal+=" ";
    }
    return temporal;
}

string real_middle(int number, int s){
    string temporal="";
    if (number==1 || number==7 || number==0){
        for (int i=0;i<s+2;i++){
            temporal+=" ";
        }
        return temporal;
    }else{
        temporal+=" ";
        for (int i=0;i<s;i++){
            temporal+="-";
        }
        temporal+=" ";
        return temporal;
    }
}

string get_middle2(int number,int s ){
    string temporal;
    if (number==2 || number==6 || number==8 || number==0){
        temporal+="|";
    }else{
        temporal+=" ";
    }
    for (int i=0;i<s;i++){
        temporal +=" ";
    }
    if(number==1 || number==3 ||number==4 || number==5 || number==6 || number==7 || number==8 || number==9 || number==0){
        temporal+="|";
    }else{
        temporal+=" ";
    }
    return temporal;
}

string get_bottom(int number, int s){
    string temporal="";
    if (number==1 || number==7 || number==4){
        for (int i=0;i<s+2;i++){
            temporal+=" ";
        }
        return temporal;
    }else{
        temporal+=" ";
        for (int i=0;i<s;i++){
            temporal+="-";
        }
        temporal+=" ";
        return temporal;
    }
}


int main(){
    vector<string> output;
    vector<int> number1;
    int  a;
    string b;
    while (cin>>a>>b){
        
        if (a==0 && b=="0"){
            return 1;
        }
        for (int i=0;i<b.length();i++){
            int temporal=b[i]-'0';
            number1.push_back(temporal);   

        }
        /*for (int i=0;i<number1.size();i++){
            cout<<number1[i]<<" ";
        }*/
        
        for (int i=0;i<2*a+3;i++){
            string temporal="";
            for (int j=0;j<number1.size();j++){
                if(i==0){
                    temporal+=get_top(number1[j],a);
                }else{
                    if(i==(2*a+3)/2){
                        temporal+=real_middle(number1[j],a);
                    }else{
                        if (i==2*a+2){
                            temporal+=get_bottom(number1[j],a);
                        }else{
                            if(i>0 && i<(2*a+3)/2){
                                temporal+=get_middle1(number1[j],a);
                            }else{
                                temporal+=get_middle2(number1[j],a);
                            }   
                        }
                    }
                }
                if(j!=number1.size()-1)
                temporal+=" ";
                

            }
            output.push_back(temporal); 
        }
        for (int i=0;i<output.size();i++){
            cout<<output[i]<<endl;
        }
        cout<<endl;

    output.clear();
    number1.clear();
    }
}
