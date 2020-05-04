#include "parser.h"

Parser::Parser() {
    state = State::Operation;
}

char* Parser::execute(char *input) {

    switch(state) {
        case State::Operation:
            break;

        case State::Value:
            break;
    }

    // if (state == 'W')
    // {

    //   for (int i = 0; i < 8; i++)
    //     address[i] = 0;
    //   for (int i = 0; i < 8; i++)
    //     data[i] = 0;
    //   current = 0;

    //   option = value;
    //   state = 'A';
    // }
    // else
    // {

    //   if (value == '#')
    //   {
    //     switch (option)
    //     {
    //     case 'R':
    //       // e.read_all();
    //       debug_eeprom((int)strtol(address, NULL, 16));
    //       //Serial.println(Radio::getCode(&e));
    //       break;
    //     case 'P':
    //       e.print();
    //       break;
    //     case 'W':
    //       e.write((int)strtol(address, NULL, 16), (int)strtol(data, NULL, 16));
    //       break;
    //     default:
    //       Serial.println("Opção inválida");
    //     }

    //     state = 'W';
    //   }
    //   else if (value == '$')
    //   {
    //     current = 0;
    //     state = 'D';
    //   }
    //   else
    //   {
    //     switch (state)
    //     {
    //     case 'A':
    //       if (current < 7)
    //       {
    //         address[current] = value;
    //         current++;
    //       }
    //       break;
    //     case 'D':
    //       if (current < 7)
    //       {
    //         data[current] = value;
    //         current++;
    //       }
    //       break;
    //     }
    //   }
    // }
}