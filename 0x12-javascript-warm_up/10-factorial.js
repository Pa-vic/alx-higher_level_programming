#!/usr/bin/node
let n = 1;
if (process.argv[2] === 1) {
  console.log('1');
} else {
  for (let i = parseInt(process.argv[2]); i > 0; i--) {
    n = n * i;
  }
  console.log(n);
}
