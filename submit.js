const fs = require('fs');
const shell = require('shelljs');
let data = JSON.parse(fs.readFileSync('./submit.json', 'utf8'));

Object.keys(data.Dependencies).forEach((key) => {
  let temp = shell.exec(`./submit.sh ${key}`);
  if(temp.stderr == ''){
    fs.appendFileSync('log.txt',`Able to install module ${key} \n`,'UTF-8');
  } else {
    fs.appendFileSync('log.txt',`Unable to install module ${key} \n`,'UTF-8')
  }
})
