import React from 'react';
import { StyleSheet, View, Image, Text, TouchableHighlight } from 'react-native';



const TabBar = props => {
    console.log(props)
  return (
    <View style={styles.container}>
        <View style={styles.viewimg}>
            <Image style={styles.img} source={require('../img/WP.png')} resizeMode='contain' />
        </View>
        <View style={styles.buttons}>
            <TouchableHighlight underlayColor="black" onPress={() => props.telaAtendimento()}>
                <Text style={styles.textButton}>
                    ATENDIMENTOS
                </Text>
            </TouchableHighlight>
            <Text style={styles.textButton}>
                RELATÓRIOS
            </Text>
            <Text style={styles.textButton}>
                CHAT
            </Text>
        </View>
    </View>
    )
}

const styles = StyleSheet.create({
    container: {
        height: 150,
        width:'100%',
        padding: 10,
        backgroundColor: '#40E0D0',
        flexDirection: 'row',
        flexWrap:'wrap',
        justifyContent:'space-between',
        alignItems:'center',
    },
    buttons: {
        flexDirection:'row',
        justifyContent:'space-between',
        alignItems:'center',
        justifyContent:'flex-end'
    },
    viewimg:{
        height:'80%',
        width:250
    },
    img:{
        height: '80%',
        width: '80%'
    },
    textButton: {
        color:'#fff',
        marginRight: 30,
        fontWeight:'bold',
        fontSize: 20
    }
})

export default TabBar;