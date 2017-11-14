#include <Cli.h>

Cli cli = Cli(Serial);

void FunctionHello(void) {
  Serial.println("\"functionHello\" is being executed!");
  Serial.print("FunctionHello() parm: ["); 
  Serial.print(cli.parm); // <== you can do something usefull with the String "cli.parm"  
  Serial.println("]");
}

void FunctionByebye(void) {Serial.println("\"functionByebye\" is being executed!");}
void FunctionSeeyou(void) {Serial.println("\"functionSeeyou\" is being executed!");}
void FunctionHelp(void) {Serial.println("==Help==\nType:\nHello\nByebye\nSeeyou\n");}

void setup(){
  cli.RegisterCmd("help",&FunctionHelp);
  cli.RegisterCmd("Hello",&FunctionHello); // <== case does not matter
  cli.RegisterCmd("ByeBye",&FunctionByebye);
  cli.RegisterCmd("seeYou",&FunctionSeeyou);
  Serial.begin(19200);

  Serial.println("Enter command or type 'help'");
}

void loop(){
  cli.Run();
    
}  






