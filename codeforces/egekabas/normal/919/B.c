#include <stdio.h>
void reverse(char result[100]){
    int lenght,i=0;
    while(result[lenght]!=0)
        ++lenght;
    char a[100];
    for(i=0;i<=lenght-1;++i)
        a[i]=result[lenght-1-i];
    for(i=0;i<lenght;++i)
        result[i]=a[i];
}       
void int_to_str(int number1,char result[100]){
    int i=0;
    int number=number1;
    for(i=0;number>0;++i){
        result[i]=number%10+'0';
        number=number/10;
    }
    result[i]='\0';
    reverse(result);
}
int str_to_int(char string[100]){
    int i,result=0;
    for(i=0;string[i]!='\0';++i){
        result=result*10+string[i]-'0';
    }
    return result;
}
int sum_of_digits(char string[100]){
  int i,value=0;
  for(i=0;string[i]!='\0';++i){
    value=value-'0'+string[i];
  }
  return value;
}
int isperfect(int number){
  char string[100];
  int_to_str(number,string);
  if(sum_of_digits(string)==10)
    return 1;
  else
    return 0;
}
int nextperfect(int first){
  int next=first+9;
  if(isperfect(next)==1)
    return next;
  else{
    for(;;++next){
      if(isperfect(next)==1)
        return next;
    }
  }
}
int main(){
  char array[100];
  scanf("%s",array);
  int k;
  k=str_to_int(array);
  int perfects=1,i=1;
  i=19;
  while(perfects<k){
    i=nextperfect(i);
    ++perfects;
  }
  printf("%d",i);
}