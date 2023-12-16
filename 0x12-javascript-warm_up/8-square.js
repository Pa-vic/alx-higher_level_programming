#!/usr/bin/node
if (isNaN(process.argv[2])) {
  console.log('Missing size');
} else {
  for (let i = 0; i < process.argv[2]; i++) {
    for (let i = 0; i < process.argv[2]; i++) {
      process.stdout.write('X');
    }
    console.log();
  }
}
