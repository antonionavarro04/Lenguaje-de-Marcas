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

const short U_DEL = 500;
const short M_DEL = 15;

int buttonStateA = LOW;
int buttonStateB = LOW;
int buttonStateC = LOW;
int buttonState1 = LOW;
int buttonState2 = LOW;
int buttonState3 = LOW;

bool needsToReset = true;
bool robot = true;

int generarNumeroAleatorio() {
  static unsigned int semilla = 0;          // Valor inicial de la semilla
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
    }
    delay(50);
  }
  Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 10);  // Pos de Espera

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
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 70, 75, 120, 160, 90, 73);
    Braccio.ServoMovement(M_DEL, 70, 135, 145, 145, 90, 73);
    Braccio.ServoMovement(M_DEL, 70, 135, 145, 145, 90, 10);
    Braccio.ServoMovement(M_DEL, 70, 75, 110, 160, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 75, 120, 180, 90, 10);
  }

  if (buttonStateA == HIGH && buttonState2 == HIGH) {
    Serial.println("STATE A2");
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 62, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 62, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 62, 75, 120, 160, 90, 73);
    Braccio.ServoMovement(M_DEL, 62, 125, 135, 170, 90, 73);
    Braccio.ServoMovement(M_DEL, 62, 125, 135, 170, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 75, 120, 180, 90, 10);
  }

  if (buttonStateA == HIGH && buttonState3 == HIGH) {
    Serial.println("STATE A3");
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 55, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 55, 90, 170, 160, 90, 73);
    Braccio.ServoMovement(M_DEL, 55, 90, 170, 160, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 75, 120, 180, 90, 10);
  }

  if (buttonStateB == HIGH && buttonState1 == HIGH) {
    Serial.println("STATE B1");
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 73);
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
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 75, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 75, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 75, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 70, 125, 130, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 70, 125, 130, 180, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 75, 120, 180, 90, 10);
  }

  if (buttonStateB == HIGH && buttonState3 == HIGH) {
    Serial.println("STATE B3");
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 67, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 67, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 67, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 67, 105, 155, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 67, 105, 155, 180, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 75, 120, 180, 90, 10);
  }

  if (buttonStateC == HIGH && buttonState1 == HIGH) {
    Serial.println("STATE C1");
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 73);
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
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 85, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 85, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 85, 75, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 85, 130, 120, 180, 90, 73);
    Braccio.ServoMovement(M_DEL, 85, 130, 120, 180, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 75, 120, 180, 90, 10);
  }

  if (buttonStateC == HIGH && buttonState3 == HIGH) {
    Serial.println("STATE C3");
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 10);
    Braccio.ServoMovement(M_DEL, 0, 90, 170, 180, 90, 73);
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

  bool bit[9];

  short userMoves[5];
  short robotMoves[4];

  for (short pos = 0; pos < previousLength; pos += 2) {
    userMoves[i] = previous[pos];
    robotMoves[i] = previous[pos + 1];
    i++;
  } i = 0;

  for (short pos = 0; pos < previousLength; pos++) {
    bit[pos] = contains(userMoves, numbers[pos]);
    i++;
  } i = 0;

  for (int pos = 0; pos < previousLength; pos++) {
    Serial.print(bit[pos]);
    Serial.print(", ");
  }

  // Bloque para comprobar
  if (bit[0] && bit[1] && bit[2]) {
    return 1;
  } else if (bit[0] && bit[3] && bit[6]) {
    return 1;
  } else if (bit[2] && bit[5] && bit[8]) {
    return 1;
  } else if (bit[8] && bit[7] && bit[6]) {
    return 1;
  } else if (bit[5] && bit[4] && bit[3]) {
    return 1;
  } else if (bit[0] && bit[4] && bit[8]) {
    return 1;
  } else if (bit[1] && bit[4] && bit[7]) {
    return 1;
  } else if (bit[2] && bit[4] && bit[6]) {
    return 1;
  }
  // Bloque para comprobar

  for (short pos = 0; pos < previousLength; pos++) {
    bit[i] = false;
  }

  for (short pos = 0; pos < previousLength; pos++) {
    bit[pos] = contains(robotMoves, numbers[pos]);
  } i = 0;

  if (bit[0] && bit[1] && bit[2]) {
    return 2;
  } else if (bit[0] && bit[3] && bit[6]) {
    return 2;
  } else if (bit[2] && bit[5] && bit[8]) {
    return 2;
  } else if (bit[8] && bit[7] && bit[6]) {
    return 2;
  } else if (bit[5] && bit[4] && bit[3]) {
    return 2;
  } else if (bit[0] && bit[4] && bit[8]) {
    return 2;
  } else if (bit[1] && bit[4] && bit[7]) {
    return 2;
  } else if (bit[2] && bit[4] && bit[6]) {
    return 2;
  } return 0;
}

void predictMove() {
  int n = 0;
  short v = 0;
  bool ended;

  do {
    n = generarNumeroAleatorio();
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
  if (won == 0) {
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
    }

    while (buttonStateA == HIGH || buttonStateB == HIGH || buttonStateC == HIGH) {
      digitalWrite(LED, HIGH);  // Encendemos el LED de Estado
      delay(U_DEL);
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
        }
        if (repeated) {
          break;
        }

        previous[turn] = save();
        move();
        won = check();
        turn++;
        needsToReset = true;
        Serial.print(": ");
        Serial.println(won);
        break;
      }
    }
  } else if (won == 1) {
    Braccio.ServoMovement(10, 50, 50, 50, 50, 50, 50);
  } else if (won == 2) {
    Braccio.ServoMovement(10, 50, 50, 50, 50, 50, 10);
  } else if (turn == 9 && won == 0) {
    Braccio.ServoMovement(10, 50, 50, 50, 50, 50, 73);
  }
}
