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
int isDigit(char check);
int isOperator(char check);
int evaluator(char* postfix);
void in_to_post(char* infix,char* postfix);
int popInt(stackInt* storage_for_eva,int* value);
int pushInt(stackInt* storage_for_eva, int value);
int pushChar(stackChar* storage , char operator);
int popChar(stackChar* storage , char* value);
int precedence(char operator);
int char_to_int(char number);
int calculate(int left ,int right,char operator);

int main(){
    char infix[max];
    char postfix[max];
    
    printf("Input must be a using decimal digits(0-9) and operators(+,-,*,/,(,),[,]),Do not use consecutive operators\n");
    printf("Input expression: ");
    scanf("%99s",infix);
    
    in_to_post(infix,postfix);
    int i = 0;

    while (postfix[i] != '\0'){
        printf("%c",postfix[i]);
        i++;
    }
    
    int output = evaluator(postfix);
    printf("\nResule After Evaluate: ");
    printf("%d",output);

    return 0;
}

void in_to_post(char* infix,char* postfix){
    stackChar operators;
    operators.top = -1;
    char operator_for_postfix; 
    char temp_for_express;
    int i = 0; 
    int j = 0;

    while(infix[i] != '\0'){
        if(infix[i] == '(' || infix[i] == '['){
            pushChar(&operators,infix[i]);
             
        }else if(isOperator(infix[i])){
            while (operators.top >= 0 &&
                   operators.data[operators.top] != '(' &&
                   operators.data[operators.top] != '[' &&
                   precedence(operators.data[operators.top]) >= precedence(infix[i])) {
                popChar(&operators, &temp_for_express);

                postfix[j++] = temp_for_express;
        }
        pushChar(&operators, infix[i]);
        }else if(closeOperator(infix[i])){
            while(operators.top >= 0 &&
                    operators.data[operators.top] != '(' &&
                    operators.data[operators.top] != '['){
                popChar(&operators, &temp_for_express);
                postfix[j++] = temp_for_express;
            }
            popChar(&operators , &temp_for_express);

        }else if(isDigit(infix[i])){
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
int pushInt(stackInt* storage_for_eva,int value){
    if(storage_for_eva->top >= max - 1){
        return 777;
    }
 
    storage_for_eva->top++;
    storage_for_eva->data[storage_for_eva->top] = value;

    return 3;
}

int popInt(stackInt* storage_for_eva , int* value){
    if(storage_for_eva->top == -1){
        return 888;
    }

    *value = storage_for_eva->data[storage_for_eva->top];
    storage_for_eva->top--;

    return 4;
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



int isDigit(char check){
    return check >= '0' && check <= '9';
}

int isOperator(char check){
    return check == '+' || check == '-' || 
           check == '*' || check == '/';
}

int closeOperator(char check){
    return check == ')' || check == ']';
}

int precedence(char operator){
    if(operator == '+' || operator == '-') return 1;
    if(operator == '*' || operator == '/') return 2;
    return 0;
}

int char_to_int(char number){
    return number - '0';
}

int calculate(int left ,int right,char operator){
    if(operator == '+'){ 
        return left + right;
    }else if(operator == '-'){
        return left - right;
    }else if(operator == '*'){
        return left * right;
    }else if(operator == '/'){
        return left / right;
    }else
        return 6;    
}

int evaluator(char* postfix){
    stackInt operand;
    operand.top = -1;
    int i = 0;
    int left,right,result;

    while(postfix[i] != '\0'){
        if(isDigit(postfix[i])){
            int value = char_to_int(postfix[i]);
            pushInt(&operand,value);
        }else if(isOperator(postfix[i])){
            popInt(&operand,&right);
            popInt(&operand,&left);

            result = calculate(left,right,postfix[i]);
            pushInt(&operand,result);
        }

        i++;
    }
    popInt(&operand,&result);

    return result;
}
