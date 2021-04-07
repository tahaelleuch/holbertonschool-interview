#!/usr/bin/node

const request = require('request');
const FilmId = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + FilmId;
request(url, function (error, response, body) {
  if (error) {
    return console.log(error);
  }
  const data = JSON.parse(body);
  const chardict = {};
  for (const car in data.characters) {
    request(data.characters[car], function (errorr, responser, bodyr) {
      if (errorr) {
        return console.log(errorr);
      }
      const Mybodychar = JSON.parse(bodyr);
      chardict[car] = Mybodychar.name;
      if (Object.values(chardict).length === data.characters.length) {
        for (const car in data.characters) {
          console.log(chardict[car]);
        }
      }
    });
  }
});
