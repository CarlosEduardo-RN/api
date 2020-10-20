import React, { Component } from 'react';
import { FlatList, StyleSheet, Text, View } from 'react-native';
import firebase from 'firebase';
import _ from 'lodash';



export default class App extends Component {
constructor(){
  super();
  this.state = { dados: ''}
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
  
  firebase.initializeApp(firebaseConfig);
  this._pegaArrayDados();
}

_pegaArrayDados(){
  
  firebase.database().ref(`json`).once("value", snapshot => this.setState({dados: snapshot.val()}));
  this.arrayEstacion = _.map(this.state.dados, (val, uid) => {return {...val, uid}});
  console.log(this.arrayEstacion);
}

  componentDidMount(){
    
    setInterval(() => this._pegaArrayDados(), 5000);
  }


  _showDataRequestApiJson(item){
    return(
      <View style={styles.container, {flexDirection:'row', marginTop: 20}}>
        <Text style={{color:'black', fontSize: 14, fontWeight:'bold', marginLeft: 10}}>{item.uid}</Text>
        <Text style={{ marginLeft: 10}}>TEMPERATURA ATUAL: </Text>
        <Text style={{ marginLeft: 10}}>{item.responseJson.temperatura}ºC</Text> 

      </View>
    )
  }


  render(){
    return (
      <View style={styles.container}>
      <meta httpEquiv="refresh" content="60"></meta>
        <View style={styles.Vtitle}>
          <Text style={styles.title}>MONITORAMENTO DE MÁQUINAS DE ESTACIONAMENTO</Text>
        </View>
        <FlatList 
        data={this.arrayEstacion}
        renderItem={({item}) => this._showDataRequestApiJson(item)}
        
        />
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff'
  },
  Vtitle:{
    justifyContent:'center',
    alignItems:'center',
    height: 100,
    width:'100%',
    backgroundColor: '#40E0D0'
  },
  title: {
    color: '#fff',
    fontSize: 30,
    fontWeight: 'bold'
  }
});
