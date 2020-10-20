import { StyleSheet } from 'react-native';

export const contStyles = StyleSheet.create({
    count:{
        height:'100%',
        width:'100%',
        backgroundColor:'#CDCDCD',
        flexDirection:'row',
    },
    container:{
        height:'100%',
        width:'100%',
        backgroundColor:'#fff',
        alignItems:'flex-end'
    }
});


export const tabStyles = StyleSheet.create({ 
    tabBar:{
        width: '15%',
        height: '100%',
        backgroundColor:'#fff',
        justifyContent:'flex-start',
        alignItems:'center'
    },
    tabBarImg:{
        height: '5%',
        width: '80%'
    },
    tabBarViewButtons: {
        height: '5%',
        width:'100%',
        marginTop: '15%'
    },
    tabBarTextButtons:{
        color:"#4682B4",
        fontSize: '115%',
        marginLeft: '30%',
        marginTop: '20%'
    },

});

export const navStyles = StyleSheet.create({
    navBar:{
        width:'85%',
        height: '7%',
        backgroundColor:'#fff',
        justifyContent:'space-between',
        flexDirection:'row',
        alignItems:'center'
    },
    profileImage:{
        height:40,
        width:40,
        borderRadius: 40,
        margin:5
    },
    textNavBarTitle:{
        marginLeft: '40%',
        fontSize: '200%'
    },
    txtNameTec:{
        flexDirection:'row',
        alignItems:'center'
    },
    txtNameTecText:{
        marginRight: 10
    }

});

export const dashStyles = StyleSheet.create({
    window:{
        height:'90%',
        width:'80%',
        backgroundColor:'#CDCDCD',
        margin: 15,
        flexWrap:'wrap'
    },
    card:{
        width: '50%',
        height:'45%',
        backgroundColor:'#fff',
        borderRadius: 15,
        alignItems:'center',
        justifyContent:'center',
        margin: 20,
        flexWrap:'wrap',
        padding: 5
    },
    viewLegendaPieChart:{
        flexDirection:'row',
        justifyContent:'space-between'
    },
    atFinalizado:{
        color:'#82ca9d',
        marginBottom:60
    },
    atNfinalizado:{
        color:'#8884d8',
        marginTop:20
    },
    txtRadar:{
        justifyContent:'flex-start',
        height:'15%'
    }
})