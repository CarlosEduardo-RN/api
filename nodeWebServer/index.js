process.title = 'WP - Web Server';
 var args = process.argv,
   port = args[2] || 7070,
   webServer = require('./server');

 webServer.listen(port, () => {
   console.log('Server started at port ' + port);
 });