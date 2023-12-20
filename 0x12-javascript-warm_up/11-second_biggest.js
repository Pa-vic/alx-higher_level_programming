#!/usr/bin/node

let number;
if (process.argv.length === 2) {
  console.log('0');
} else if (process.argv.length > 2) {
  number = process.argv[2];
  for (let i = 3; i <= process.argv.length; i++) {
    if (process.argv[i] > number) {
      number = process.argv[i];
    }
  }
  console.log(number);
}
