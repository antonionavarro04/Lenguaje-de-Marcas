#include <Braccio.h>
#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

short unsigned turn = 0;
short unsigned won = 0;

short previous[9];
const short numbers[9] = {
  1, 2, 3, 11, 12, 13, 21, 22, 23
};

const short previousLength = 9;

const String UL_STR = "Upper Left";
const String UM_STR = "Upper Middle";
const String UR_STR = "Upper Right";
const String ML_STR = "Middle Left";
const String MM_STR = "Middle Middle";
const String MR_STR = "Middle Right";
const String LL_STR = "Lower Left";
const String LM_STR = "Lower Middle";
const String LR_STR = "Lower Right";

const short UL = 3;
const short UM = 2;
const short UR = 1;
const short ML = 13;
const short MM = 12;
const short MR = 11;
const short LL = 23;
const short LM = 22;
const short LR = 21;

const int BUTTON_A = 2;
const int BUTTON_B = 8;
const int BUTTON_C = 4;
const int LED = 7;

const short U_DEL = 200;
const short M_DEL = 15;

const short ROBOT_POS = 35;
const short HUMAN_POS = 0;

short humanHeight = 55;
short robotHeight = 55;

int buttonStateA = LOW;
int buttonStateB = LOW;
int buttonStateC = LOW;
int buttonState1 = LOW;
int buttonState2 = LOW;
int buttonState3 = LOW;

bool needsToReset = true;
bool robot = true;
bool alt = true;

void newGame() {
  robot = true;
  alt = true;
  needsToReset = true;
  humanHeight = 55;
  robotHeight = 60;
  turn = 0;
  won = 0;

  for (short pos = 0; pos < previousLength; pos++) {
    previous[pos] = 0;
  } Serial.println("All variables reseted...");
}

int rng() {
  static unsigned long semilla = random(random());
  semilla = (semilla * 32719 + 3) % 32749;  // Fórmula para generar un número pseudoaleatorio
  return semilla % 9;                       // Devuelve un número entre 0 y 8 (exclusivo)
}

bool contains(short a[], short n) {
  bool state = false;
  for (short pos = 0; pos < sizeof(a) / sizeof(a[0]); pos++) {
    if (a[pos] == n) {
      state = true;
      break;
    }
  }
  return state;
}

void fill(short a[], short v) {
  for (short pos = 0; pos < sizeof(a) / sizeof(a[0]); pos++) {
    a[pos] = v;
  }
}

void reset() {
  Serial.print("RESETING...");
  Serial.println();
  short s = HIGH;

  if (robot == true) {
    robot = false;
  } else {
    robot = true;
  }

  for (int i = 1; i <= 30; i++) {  // Blinking
    digitalWrite(LED, s);
    if (s == HIGH) {
      s = LOW;
    } else {
      s = HIGH;
    } delay(50);
  } if (robot) {
    Braccio.ServoMovement(M_DEL, ROBOT_POS, robotHeight, 170, 180, 90, 10);  // Pos de Espera
  } else {
    Braccio.ServoMovement(M_DEL, HUMAN_POS, humanHeight, 170, 180, 90, 10);  // Pos de Espera
  }

  buttonStateA = LOW;  // Reset de Variables
  buttonStateB = LOW;
  buttonStateC = LOW;
  buttonState1 = LOW;
  buttonState2 = LOW;
  buttonState3 = LOW;

  digitalWrite(LED, LOW);  // Apagamos el LED de Estado
  needsToReset = false;
}

void move() {
  if (buttonStateA == HIGH && buttonState1 == HIGH) {
    Serial.println("STATE A1");
    Braccio.ServoMovement(M_DEL, 70, 75, 120, 160, 90, 73);
    Braccio.ServoMovement(M_DEL, 70, 135, 145, 145, 90, 73);
    Braccio.ServoMovement(M_DEL, 70, 135, 145, 145, 90, 10);
    Braccio.ServoMovement(M_DEL, 70, 75, 110, 160, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 75, 120, 180, 90, 10);
  }

  if (buttonStateA == HIGH && buttonState2 == HIGH) {
    Serial.println("STATE A2");
    Braccio.ServoMovement(M_DEL, 62, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 62, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 62, 75, 120, 160, 90, 73);
    Braccio.ServoMovement(M_DEL, 62, 125, 135, 170, 90, 73);
    Braccio.ServoMovement(M_DEL, 62, 125, 135, 170, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 75, 120, 180, 90, 10);
  }

  if (buttonStateA == HIGH && buttonState3 == HIGH) {
    Serial.println("STATE A3");
    Braccio.ServoMovement(M_DEL, 55, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 55, 90, 170, 160, 90, 73);
    Braccio.ServoMovement(M_DEL, 55, 90, 170, 160, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 75, 120, 180, 90, 10);
  }

  if (buttonStateB == HIGH && buttonState1 == HIGH) {
    Serial.println("STATE B1");
    Braccio.ServoMovement(M_DEL, 60, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 60, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 75, 75, 120, 160, 90, 73);
    Braccio.ServoMovement(M_DEL, 75, 120, 150, 150, 90, 73);
    Braccio.ServoMovement(M_DEL, 75, 120, 150, 150, 90, 10);
    Braccio.ServoMovement(M_DEL, 75, 75, 150, 160, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 75, 120, 180, 90, 10);
  }

  if (buttonStateB == HIGH && buttonState2 == HIGH) {
    Serial.println("STATE B2");
    Braccio.ServoMovement(M_DEL, 75, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 75, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 75, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 70, 125, 130, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 70, 125, 130, 180, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 75, 120, 180, 90, 10);
  }

  if (buttonStateB == HIGH && buttonState3 == HIGH) {
    Serial.println("STATE B3");
    Braccio.ServoMovement(M_DEL, 67, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 67, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 67, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 67, 105, 155, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 67, 105, 155, 180, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 75, 120, 180, 90, 10);
  }

  if (buttonStateC == HIGH && buttonState1 == HIGH) {
    Serial.println("STATE C1");
    Braccio.ServoMovement(M_DEL, 87, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 87, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 87, 75, 120, 160, 90, 73);
    Braccio.ServoMovement(M_DEL, 87, 125, 140, 160, 90, 73);
    Braccio.ServoMovement(M_DEL, 87, 125, 140, 160, 90, 10);
    Braccio.ServoMovement(M_DEL, 87, 75, 120, 160, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 75, 120, 180, 90, 10);
  }

  if (buttonStateC == HIGH && buttonState2 == HIGH) {
    Serial.println("STATE C2");
    Braccio.ServoMovement(M_DEL, 85, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 85, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 85, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 85, 130, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 85, 130, 120, 180, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 75, 120, 180, 90, 10);
  }

  if (buttonStateC == HIGH && buttonState3 == HIGH) {
    Serial.println("STATE C3");
    Braccio.ServoMovement(M_DEL, 85, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 85, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 85, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 85, 95, 170, 170, 90, 73);
    Braccio.ServoMovement(M_DEL, 85, 95, 170, 170, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 75, 120, 180, 90, 10);
  }
}

short save() {
  short n = 0;

  if (buttonStateB == HIGH) {
    n += 10;
  } else if (buttonStateC == HIGH) {
    n += 20;
  }
  if (buttonState1 == HIGH) {
    n++;
  } else if (buttonState2 == HIGH) {
    n += 2;
  } else if (buttonState3 == HIGH) {
    n += 3;
  }
  return n;
}

short check() {
  short i = 0;
  short j = 0;

  short tablero[9];

  for (short pos = 0; pos < 9; pos++) {
    tablero[pos] = 0;
  }

  short userMoves[5];
  short robotMoves[4];

  for (short pos = 0; pos < previousLength; pos++) {
    i = 0;
    j = 0;

    for (short k = 0; k < previousLength; k++) { // Sacamos la posición del numero
      if (numbers[k] == previous[pos]) {
        j = k;
        break;
      }
    }
    
    if (previous[pos] != 0) { // Si ha tirado
      if (pos % 2 == 0) {
        i = 1;
      } else {
        i = 2;
      } tablero[j] = i;
    }
  }

  for (int pos = 0; pos < previousLength; pos++) {
    Serial.print(tablero[pos]);
    Serial.print(", ");
  }
  
  if (turn % 2 == 0) { // human
    i = 1;
  } else { // robot
    i = 2;
  }

  // Bloque para comprobar
  if (tablero[0] == i && tablero[1] == i && tablero[2] == i) {
    return i;
  } else if (tablero[0] == i && tablero[3] == i && tablero[6] == i) {
    return i;
  } else if (tablero[2] == i && tablero[5] == i && tablero[8] == i) {
    return i;
  } else if (tablero[8] == i && tablero[7] == i && tablero[6] == i) {
    return i;
  } else if (tablero[5] == i && tablero[4] == i && tablero[3] == i) {
    return i;
  } else if (tablero[0] == i && tablero[4] == i && tablero[8] == i) {
    return i;
  } else if (tablero[1] == i && tablero[4] == i && tablero[7] == i) {
    return i;
  } else if (tablero[2] == i && tablero[4] == i && tablero[6] == i) {
    return i;
  } return 0;
}

void predictMove() {
  int n = 0;
  short v = 0;
  bool ended;

  do {
    n = rng();
    v = numbers[n];
    ended = true;

    for (short pos = 0; pos < previousLength; pos++) {
      if (v == previous[pos]) {
        ended = false;
        break;
      }
    }
    Serial.println(n);
    Serial.println(numbers[n]);
  } while (!ended);

  switch (v) {
    case UL:
      buttonStateA = HIGH;
      buttonState3 = HIGH;
      break;

    case UM:
      buttonStateA = HIGH;
      buttonState2 = HIGH;
      break;

    case UR:
      buttonStateA = HIGH;
      buttonState1 = HIGH;
      break;

    case ML:
      buttonStateB = HIGH;
      buttonState3 = HIGH;
      break;

    case MM:
      buttonStateB = HIGH;
      buttonState2 = HIGH;
      break;

    case MR:
      buttonStateB = HIGH;
      buttonState1 = HIGH;
      break;

    case LL:
      buttonStateC = HIGH;
      buttonState3 = HIGH;
      break;

    case LM:
      buttonStateC = HIGH;
      buttonState2 = HIGH;
      break;

    case LR:
      buttonStateC = HIGH;
      buttonState1 = HIGH;
      break;
  }
}

void setup() {
  Braccio.begin();

  Serial.begin(9600);

  pinMode(BUTTON_A, INPUT);
  pinMode(BUTTON_B, INPUT);
  pinMode(BUTTON_C, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (won == 0 && turn != 9) {
    rng();
    
    if (needsToReset) {
      reset();
    }

    Serial.println("READY");

    Serial.print("[");
    for (short pos = 0; pos < previousLength; pos++) {
      if (previous[pos] != 0) {
        switch (previous[pos]) {
          case UL:
            Serial.print(UL_STR);
            break;

          case UM:
            Serial.print(UM_STR);
            break;

          case UR:
            Serial.print(UR_STR);
            break;

          case ML:
            Serial.print(ML_STR);
            break;

          case MM:
            Serial.print(MM_STR);
            break;

          case MR:
            Serial.print(MR_STR);
            break;

          case LL:
            Serial.print(LL_STR);
            break;

          case LM:
            Serial.print(LM_STR);
            break;

          case LR:
            Serial.print(LR_STR);
            break;

          default:
            Serial.print("Undefined");
            break;
        }
        if ((turn - 1) != pos) {
          Serial.print(", ");
        }
      }
    }
    Serial.println("]");

    delay(U_DEL);

    if (robot) {
      predictMove();
    }

    // Leemos los Botones
    if (!robot) {
      buttonStateA = digitalRead(BUTTON_A);
      buttonStateB = digitalRead(BUTTON_B);
      buttonStateC = digitalRead(BUTTON_C);
    } alt = true;

    while (buttonStateA == HIGH || buttonStateB == HIGH || buttonStateC == HIGH) {
      digitalWrite(LED, HIGH);  // Encendemos el LED de Estado
      if (alt && !robot) {
        delay(500);
        alt = false;
      } delay(U_DEL);
      Serial.println("STATE W");

      // Leemos los demás botones
      if (!robot) {
        buttonState1 = digitalRead(BUTTON_A);
        buttonState2 = digitalRead(BUTTON_B);
        buttonState3 = digitalRead(BUTTON_C);
      }

      if (buttonState1 == HIGH || buttonState2 == HIGH || buttonState3 == HIGH) {
        short val = save();
        bool repeated = false;
        for (short pos = 0; pos < previousLength; pos++) {
          if (val == previous[pos]) {
            Braccio.ServoMovement(10, 0, 45, 170, 180, 90, 10);
            Braccio.ServoMovement(10, 0, 45, 90, 90, 90, 73);
            Braccio.ServoMovement(10, 0, 90, 170, 180, 90, 10);

            if (robot == true) {
              robot = false;
            } else {
              robot = true;
            }

            needsToReset = true;
            repeated = true;
            break;
          }
        } if (repeated) {
          break;
        }

        previous[turn] = save();

        if (robot) {
          Braccio.ServoMovement(M_DEL, ROBOT_POS, robotHeight, 170, 180, 90, 73);
          Braccio.ServoMovement(M_DEL, ROBOT_POS, 0, 170, 180, 90, 73);
          robotHeight += 10;
        } else {
          Braccio.ServoMovement(M_DEL, HUMAN_POS, humanHeight, 170, 180, 90, 73);
          Braccio.ServoMovement(M_DEL, HUMAN_POS, 0, 170, 180, 90, 73);
          humanHeight += 9;
        }

        move();
        won = check();
        turn++;
        needsToReset = true;
        Serial.print(": ");
        Serial.println(won);
        break;
      }
    }
  } else if (turn == 9 && won == 0) {
    Braccio.ServoMovement(10, 50, 50, 50, 50, 50, 73);
  } else {
    if (won == 1) {
      Braccio.ServoMovement(10, 0, 70, 180, 0, 90, 73); // Choqar
    } else {
      Braccio.ServoMovement(10, 0, 60, 180, 90, 180, 73); // Dar la mano
    } for (int i = 30; i != 0; i--) {
      Serial.print("Seconds Remaining: "); Serial.print(i); Serial.println();
      buttonStateA = digitalRead(BUTTON_A);
      buttonStateA = digitalRead(BUTTON_B);                              
      buttonStateA = digitalRead(BUTTON_C);
      if (buttonStateA == HIGH) {
        break;
      } delay(1000);
    } newGame();
  }
}
