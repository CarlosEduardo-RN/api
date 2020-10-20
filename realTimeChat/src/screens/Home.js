import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

// import { Container } from './styles';

const Home = () => {
  return( 
  <View style={styles.container}>
      <Text>
          Home Screen
      </Text>
      <View style={{backgroundColor:"red", width: '100%', height:'100%'}}>
        <Text>oi</Text>
      </View>
  </View>
  );
}

const styles = StyleSheet.create({
  container:{
    height:'100%',
    width:'100%',
    backgroundColor:'#fff',
    padding: 10
  }
})


export default Home;