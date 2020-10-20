import React, { Component } from 'react';
import { View, FlatList, Text } from 'react-native';
import firebase from 'firebase';
import _ from 'lodash';

import dataRequest from './src/api/dataRequest';


class App extends Component {

  constructor(props){
    super(props);
    this.state = { dados: '',countries: [], loading: true }
  }

  componentWillMount(){
    var firebaseConfig = {
      apiKey: "AIzaSyAwIjWFRnsQetbCrn3zaMQBuvzMN6ad0AE",
      authDomain: "apijson-423fc.firebaseapp.com",
      databaseURL: "https://apijson-423fc.firebaseio.com",
      projectId: "apijson-423fc",
      storageBucket: "apijson-423fc.appspot.com",
      messagingSenderId: "744533168757",
      appId: "1:744533168757:web:4653b62acf5139fcdf1e3c"
    };
    if (!firebase.apps.length) {
    firebase.initializeApp(firebaseConfig);
    }
    this._pegaDados();
    this.estacion = 'LOCALPARK';
  }




  componentDidMount() {
    const countries = dataRequest.getAll();
    this.setState({ countries, loading: false });
    setInterval(() => this._pegaDados(), 5000);

  }

  _pegaDados(){
    firebase.database().ref(`json/${this.estacion}`).once("value", snapshot => this.setState({dados: snapshot.val()}))
    this.dadosFirebase = _.map(this.state.dados, (val, uid) => {return{...val,uid}});
    console.log(this.dadosFirebase)
  }

  render() {
    console.log('renderizou')
    return (
      <View>
        <meta httpEquiv="refresh" content="60"></meta>
        <Text>TESTE</Text>
        <FlatList
          data={this.dadosFirebase}
          renderItem={ ({item}) => {return( <View><Text>TEMPERATURA: </Text><Text>{item.temperatura}</Text></View>)} }
        />
      </View>
    );
  }
}

export default App;