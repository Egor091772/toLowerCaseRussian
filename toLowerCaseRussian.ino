
void setup() {
  Serial.begin(9600);
  String msg = "АБёЁЖЯя123fFAG";
  msg = toLowerCaseRussian(msg);
  Serial.println(msg);
}

void loop() {
}


String toLowerCaseRussian(String input) {
  String output = "";

  for (int i = 0; i < input.length(); i++) {
    if (input[i] == 208) {        // если символы кириллицы
      if (input[i + 1] == 129) {  // для буквы Ё
        output += char(209);
        output += char(145);
      }
      else if (input[i + 1] < 160) { // Для букв [А-П]
        output += char(208);
        output += char(input[i + 1] + 32);
      }
      else if (input[i + 1] < 176) { // Для букв [Р-Я]
        output += char(209);
        output += char(input[i + 1] - 32);
      }
      else { // для букв [а-п]
        output += char(208);
        output += char(input[i + 1]);
      }
      i++;
    }
    else if (input[i] == 209) {   // для букв [р-я] и ё
      output += char(209);
      output += char(input[i + 1]);
      i++;
    }
    else {   // пришла латиница
      // для букв - переводим в нижний регистр
      if (input[i] >= 65 && input[i] <= 90) {
        output += (char)(input[i] + 32);
      }
      // остальные символы оставляем как есть
      else output += (char)input[i];
    }
  }

  return output;
}
