import firebase from 'firebase';

const estacion = 'LOCALPARK';

export var firebaseConfig = {
  apiKey: "AIzaSyAwIjWFRnsQetbCrn3zaMQBuvzMN6ad0AE",
  authDomain: "apijson-423fc.firebaseapp.com",
  databaseURL: "https://apijson-423fc.firebaseio.com",
  projectId: "apijson-423fc",
  storageBucket: "apijson-423fc.appspot.com",
  messagingSenderId: "744533168757",
  appId: "1:744533168757:web:4653b62acf5139fcdf1e3c"
};

firebase.initializeApp(firebaseConfig);

const URL = 'http://10.61.0.98:80';

async function getAll() {
  
  console.log("API")
  try {
    const response = await fetch(URL)
    const responseJson = await response.json()
    console.log(responseJson)

    firebase.database().ref(`json/${estacion}`).set({ responseJson }).catch(err => console.log(err));

  } 
  catch (error) {
    firebase.database().ref('json/logs/error').set({ error })
    .then(() => console.log(error))
    .catch(err => console.log(err));
      
  }
}

const dataRequest = {
  getAll,
};

export default dataRequest;