#include <stdio.h>
#define max 100

typedef struct{
    char data[max];
    int top;
} stackChar;

typedef struct{
    int data[max];
    int top;
} stackInt;

int closeOperator(char check);
int isDegit(char check);
int isOperator(char check);
int evalute();
void in_to_post(char* infix,char* postfix);
void pop();
int pushChar(stackChar* storage , char operator);
int popChar(stackChar* storage , char* value);


int main(){
    char infix[max];
    char postfix[max];
    printf("input expression: ");
    scanf("%99s",infix);
    

    in_to_post(infix,postfix);
    int i = 0;

    while (postfix[i] != '\0'){
        printf("%c",postfix[i]);
        i++;
}

    return 0;
}

void in_to_post(char* infix,char* postfix){
    stackChar operators;
    char operator_for_postfix; 
    operators.top = -1;
    char temp_for_express;
    int i = 0; 
    int j = 0;

    while(infix[i] != '\0'){
        if(isOperator(infix[i])){
            pushChar(&operators,infix[i]);
             
        }else if(closeOperator(infix[i])){
            while (operators.top >= 0 &&
                   operators.data[operators.top] != '(' &&
                   operators.data[operators.top] != '[') {
                popChar(&operators, &temp_for_express);
                postfix[j++] = temp_for_express;
        }
        popChar(&operators, &temp_for_express);
          
        }else if(isDegit(infix[i])){
            postfix[j] = infix[i];
            j++;
        }
        i++;
    }
    while(operators.top >= 0){
        popChar(&operators,&operator_for_postfix);
        postfix[j] = operator_for_postfix;
        j++;
    }
    postfix[j] = '\0';


}

int pushChar(stackChar* storage ,char operator){
    
    if(storage->top >= max - 1){
        return 555;
    }

    storage->top++;
    storage->data[storage->top] = operator;

    return 1;
}

int popChar(stackChar* storage, char* value){
    if(storage->top == -1){
        return 666;
    }

    *value = storage->data[storage->top];
    storage->top--;

    return 2;
}



int isDegit(char check){
    return check >= '0' && check <= '9';
}

int isOperator(char check){
    return check == '+' || check == '-' || 
           check == '*' || check == '/' ||
           check == '(' || check == '[';
}

int closeOperator(char check){
    return check == ')' || check == ']';
}
