const addon = require('./build/Release/addon');

addon.readFromFile('test.txt', (err, content) => {
  console.log(content);
})